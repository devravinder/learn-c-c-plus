#ifndef TASK_H
#define TASK_H

void addTask(const char *title);
void listTasks();
void updateTask(int index, const char *status);
void deleteTask(int index);

#endif
