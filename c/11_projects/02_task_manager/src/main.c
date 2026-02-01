#include <stdio.h>
#include "task.h"

int main() {

    int choice;
    char title[100];
    int index;

    while (1) {

        printf("\n1 Add Task\n2 List Tasks\n3 Update Task\n4 Delete Task\n0 Exit\nChoice: ");
        scanf("%d", &choice);
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
                scanf("%d",&index);
                updateTask(index,"done");
                break;

            case 4:
                printf("Index: ");
                scanf("%d",&index);
                deleteTask(index);
                break;

            case 0:
                return 0;
        }
    }
}
