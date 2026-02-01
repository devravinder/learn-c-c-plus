#include "task.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

#define FILE_PATH "data/tasks.json"

cJSON* loadJSON() {

    FILE *f = fopen(FILE_PATH, "r");
    if (!f) return cJSON_CreateArray();

    fseek(f, 0, SEEK_END);
    long len = ftell(f);
    rewind(f);

    char *data = malloc(len + 1);
    fread(data, 1, len, f);
    data[len] = 0;

    fclose(f);

    cJSON *json = cJSON_Parse(data);
    free(data);

    return json ? json : cJSON_CreateArray();
}

void saveJSON(cJSON *json) {

    char *out = cJSON_Print(json);

    FILE *f = fopen(FILE_PATH, "w");
    fputs(out, f);
    fclose(f);

    free(out);
}

void addTask(const char *title) {

    cJSON *tasks = loadJSON();

    cJSON *task = cJSON_CreateObject();
    cJSON_AddStringToObject(task, "title", title);
    cJSON_AddStringToObject(task, "status", "pending");

    cJSON_AddItemToArray(tasks, task);
    saveJSON(tasks);

    cJSON_Delete(tasks);
}

void listTasks() {

    cJSON *tasks = loadJSON();
    int size = cJSON_GetArraySize(tasks);

    for (int i = 0; i < size; i++) {

        cJSON *t = cJSON_GetArrayItem(tasks, i);
        printf("%d. %s [%s]\n",
               i,
               cJSON_GetObjectItem(t,"title")->valuestring,
               cJSON_GetObjectItem(t,"status")->valuestring);
    }

    cJSON_Delete(tasks);
}

void updateTask(int index, const char *status) {

    cJSON *tasks = loadJSON();
    cJSON *t = cJSON_GetArrayItem(tasks, index);

    if (t)
        cJSON_ReplaceItemInObject(t, "status", cJSON_CreateString(status));

    saveJSON(tasks);
    cJSON_Delete(tasks);
}

void deleteTask(int index) {

    cJSON *tasks = loadJSON();
    cJSON_DeleteItemFromArray(tasks, index);

    saveJSON(tasks);
    cJSON_Delete(tasks);
}
