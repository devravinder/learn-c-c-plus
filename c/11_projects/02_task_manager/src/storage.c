#include "storage.h"
#include <cjson/cJSON.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool storage_save(const TaskList *list, const char *filename) {
    if (!list || !filename) return false;
    
    cJSON *root = cJSON_CreateObject();
    if (!root) return false;
    
    cJSON *tasks_array = cJSON_CreateArray();
    if (!tasks_array) {
        cJSON_Delete(root);
        return false;
    }
    
    for (int i = 0; i < list->count; i++) {
        const Task *task = &list->tasks[i];
        cJSON *task_obj = cJSON_CreateObject();
        
        if (!task_obj) {
            cJSON_Delete(root);
            return false;
        }
        
        cJSON_AddNumberToObject(task_obj, "id", task->id);
        cJSON_AddStringToObject(task_obj, "title", task->title);
        cJSON_AddStringToObject(task_obj, "description", task->description);
        cJSON_AddStringToObject(task_obj, "status", task_status_to_string(task->status));
        cJSON_AddNumberToObject(task_obj, "created_at", (double)task->created_at);
        cJSON_AddNumberToObject(task_obj, "updated_at", (double)task->updated_at);
        
        cJSON_AddItemToArray(tasks_array, task_obj);
    }
    
    cJSON_AddItemToObject(root, "tasks", tasks_array);
    cJSON_AddNumberToObject(root, "count", list->count);
    
    char *json_string = cJSON_Print(root);
    if (!json_string) {
        cJSON_Delete(root);
        return false;
    }
    
    FILE *file = fopen(filename, "w");
    if (!file) {
        free(json_string);
        cJSON_Delete(root);
        return false;
    }
    
    fprintf(file, "%s", json_string);
    fclose(file);
    
    free(json_string);
    cJSON_Delete(root);
    
    return true;
}

TaskList* storage_load(const char *filename) {
    if (!filename) return NULL;
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        // File doesn't exist, return empty list
        return task_list_create();
    }
    
    // Get file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    if (file_size <= 0) {
        fclose(file);
        return task_list_create();
    }
    
    // Read file content
    char *buffer = malloc(file_size + 1);
    if (!buffer) {
        fclose(file);
        return NULL;
    }
    
    size_t read_size = fread(buffer, 1, file_size, file);
    buffer[read_size] = '\0';
    fclose(file);
    
    // Parse JSON
    cJSON *root = cJSON_Parse(buffer);
    free(buffer);
    
    if (!root) {
        return task_list_create();
    }
    
    TaskList *list = task_list_create();
    if (!list) {
        cJSON_Delete(root);
        return NULL;
    }
    
    cJSON *tasks_array = cJSON_GetObjectItem(root, "tasks");
    if (!cJSON_IsArray(tasks_array)) {
        cJSON_Delete(root);
        return list;
    }
    
    int array_size = cJSON_GetArraySize(tasks_array);
    
    for (int i = 0; i < array_size; i++) {
        cJSON *task_obj = cJSON_GetArrayItem(tasks_array, i);
        if (!cJSON_IsObject(task_obj)) continue;
        
        // Ensure capacity
        if (list->count >= list->capacity) {
            list->capacity *= 2;
            Task *new_tasks = realloc(list->tasks, sizeof(Task) * list->capacity);
            if (!new_tasks) {
                cJSON_Delete(root);
                task_list_destroy(list);
                return NULL;
            }
            list->tasks = new_tasks;
        }
        
        Task *task = &list->tasks[list->count];
        
        cJSON *id = cJSON_GetObjectItem(task_obj, "id");
        cJSON *title = cJSON_GetObjectItem(task_obj, "title");
        cJSON *description = cJSON_GetObjectItem(task_obj, "description");
        cJSON *status = cJSON_GetObjectItem(task_obj, "status");
        cJSON *created_at = cJSON_GetObjectItem(task_obj, "created_at");
        cJSON *updated_at = cJSON_GetObjectItem(task_obj, "updated_at");
        
        if (cJSON_IsNumber(id)) task->id = id->valueint;
        else task->id = 0;
        
        if (cJSON_IsString(title)) {
            strncpy(task->title, title->valuestring, MAX_TITLE_LENGTH - 1);
            task->title[MAX_TITLE_LENGTH - 1] = '\0';
        } else {
            task->title[0] = '\0';
        }
        
        if (cJSON_IsString(description)) {
            strncpy(task->description, description->valuestring, MAX_DESC_LENGTH - 1);
            task->description[MAX_DESC_LENGTH - 1] = '\0';
        } else {
            task->description[0] = '\0';
        }
        
        if (cJSON_IsString(status)) {
            task->status = task_string_to_status(status->valuestring);
        } else {
            task->status = STATUS_PENDING;
        }
        
        if (cJSON_IsNumber(created_at)) {
            task->created_at = (time_t)created_at->valuedouble;
        } else {
            task->created_at = time(NULL);
        }
        
        if (cJSON_IsNumber(updated_at)) {
            task->updated_at = (time_t)updated_at->valuedouble;
        } else {
            task->updated_at = task->created_at;
        }
        
        list->count++;
    }
    
    cJSON_Delete(root);
    return list;
}