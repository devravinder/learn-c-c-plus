#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

TaskList* task_list_create(void) {
    TaskList *list = malloc(sizeof(TaskList));
    if (!list) return NULL;
    
    list->capacity = 10;
    list->count = 0;
    list->tasks = malloc(sizeof(Task) * list->capacity);
    
    if (!list->tasks) {
        free(list);
        return NULL;
    }
    
    return list;
}

void task_list_destroy(TaskList *list) {
    if (list) {
        free(list->tasks);
        free(list);
    }
}

static int get_next_id(TaskList *list) {
    int max_id = 0;
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id > max_id) {
            max_id = list->tasks[i].id;
        }
    }
    return max_id + 1;
}

int task_add(TaskList *list, const char *title, const char *description) {
    if (!list || !title) return -1;
    
    // Resize if needed
    if (list->count >= list->capacity) {
        list->capacity *= 2;
        Task *new_tasks = realloc(list->tasks, sizeof(Task) * list->capacity);
        if (!new_tasks) return -1;
        list->tasks = new_tasks;
    }
    
    Task *task = &list->tasks[list->count];
    task->id = get_next_id(list);
    strncpy(task->title, title, MAX_TITLE_LENGTH - 1);
    task->title[MAX_TITLE_LENGTH - 1] = '\0';
    
    if (description) {
        strncpy(task->description, description, MAX_DESC_LENGTH - 1);
        task->description[MAX_DESC_LENGTH - 1] = '\0';
    } else {
        task->description[0] = '\0';
    }
    
    task->status = STATUS_PENDING;
    task->created_at = time(NULL);
    task->updated_at = task->created_at;
    
    list->count++;
    return task->id;
}

bool task_update(TaskList *list, int id, const char *title, const char *description, TaskStatus status) {
    Task *task = task_find_by_id(list, id);
    if (!task) return false;
    
    if (title) {
        strncpy(task->title, title, MAX_TITLE_LENGTH - 1);
        task->title[MAX_TITLE_LENGTH - 1] = '\0';
    }
    
    if (description) {
        strncpy(task->description, description, MAX_DESC_LENGTH - 1);
        task->description[MAX_DESC_LENGTH - 1] = '\0';
    }
    
    task->status = status;
    task->updated_at = time(NULL);
    
    return true;
}

bool task_delete(TaskList *list, int id) {
    if (!list) return false;
    
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            // Shift remaining tasks
            for (int j = i; j < list->count - 1; j++) {
                list->tasks[j] = list->tasks[j + 1];
            }
            list->count--;
            return true;
        }
    }
    
    return false;
}

Task* task_find_by_id(TaskList *list, int id) {
    if (!list) return NULL;
    
    for (int i = 0; i < list->count; i++) {
        if (list->tasks[i].id == id) {
            return &list->tasks[i];
        }
    }
    
    return NULL;
}

const char* task_status_to_string(TaskStatus status) {
    switch (status) {
        case STATUS_PENDING: return "pending";
        case STATUS_IN_PROGRESS: return "in_progress";
        case STATUS_COMPLETED: return "completed";
        default: return "unknown";
    }
}

TaskStatus task_string_to_status(const char *str) {
    if (strcmp(str, "in_progress") == 0) return STATUS_IN_PROGRESS;
    if (strcmp(str, "completed") == 0) return STATUS_COMPLETED;
    return STATUS_PENDING;
}

void task_print(const Task *task) {
    if (!task) return;
    
    char created[26], updated[26];
    struct tm *tm_info;
    
    tm_info = localtime(&task->created_at);
    strftime(created, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    tm_info = localtime(&task->updated_at);
    strftime(updated, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    
    printf("\n--- Task #%d ---\n", task->id);
    printf("Title: %s\n", task->title);
    printf("Description: %s\n", task->description);
    printf("Status: %s\n", task_status_to_string(task->status));
    printf("Created: %s\n", created);
    printf("Updated: %s\n", updated);
    printf("---------------\n");
}

void task_print_all(const TaskList *list) {
    if (!list || list->count == 0) {
        printf("\nNo tasks found.\n");
        return;
    }
    
    printf("\n=== Task List (%d tasks) ===\n", list->count);
    for (int i = 0; i < list->count; i++) {
        task_print(&list->tasks[i]);
    }
}