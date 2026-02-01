#include <stdio.h>
#include <string.h>
#include "task.h"

int main() {

    int choice;
    char title[100];
    char status[50];
    int index;

    while (1) {

        printf("\n1 Add Task\n2 List Tasks\n3 Update Task\n4 Delete Task\n0 Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        getchar();

        switch(choice) {

            case 1:
                printf("Title: ");
                fgets(title,100,stdin);
                title[strcspn(title,"\n")] = 0;
                addTask(title);
                break;

            case 2:
                listTasks();
                break;

            case 3:
                printf("Index: ");
                if (scanf("%d",&index) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid index.\n");
                    break;
                }
                getchar(); // Consume newline after scanf
                printf("Status: ");
                fgets(status, 50, stdin);
                status[strcspn(status, "\n")] = 0;
                updateTask(index, status);
                break;

            case 4:
                printf("Index: ");
                if (scanf("%d",&index) != 1) {
                    while (getchar() != '\n');
                    printf("Invalid index.\n");
                    break;
                }
                deleteTask(index);
                break;

            case 0:
                return 0;
        }
    }
}
