#ifndef STORAGE_H
#define STORAGE_H

#include "task.h"
#include <stdbool.h>

// #define STORAGE_FILE "tasks.json" // stores in build
#define STORAGE_FILE "data/tasks.json"  // Relative path ( create data folder )


// Storage operations
bool storage_save(const TaskList *list, const char *filename);
TaskList* storage_load(const char *filename);

#endif // STORAGE_H