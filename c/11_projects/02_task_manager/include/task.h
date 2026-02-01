#ifndef TASK_H
#define TASK_H

#include <stdbool.h>
#include <time.h>

#define MAX_TITLE_LENGTH 100
#define MAX_DESC_LENGTH 500

typedef enum {
    STATUS_PENDING,
    STATUS_IN_PROGRESS,
    STATUS_COMPLETED
} TaskStatus;

typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    TaskStatus status;
    time_t created_at;
    time_t updated_at;
} Task;

typedef struct {
    Task *tasks;
    int count;
    int capacity;
} TaskList;

// Task operations
TaskList* task_list_create(void);
void task_list_destroy(TaskList *list);
int task_add(TaskList *list, const char *title, const char *description);
bool task_update(TaskList *list, int id, const char *title, const char *description, TaskStatus status);
bool task_delete(TaskList *list, int id);
Task* task_find_by_id(TaskList *list, int id);
void task_print(const Task *task);
void task_print_all(const TaskList *list);
const char* task_status_to_string(TaskStatus status);
TaskStatus task_string_to_status(const char *str);

#endif // TASK_H