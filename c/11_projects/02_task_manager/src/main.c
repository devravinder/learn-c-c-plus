#include "task.h"
#include "storage.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_menu(void) {
    printf("\n======== Task Manager ========\n");
    printf("1. Add Task\n");
    printf("2. View All Tasks\n");
    printf("3. Update Task\n");
    printf("4. Delete Task\n");
    printf("5. View Task by ID\n");
    printf("6. Save and Exit\n");
    printf("==============================\n");
    printf("Enter choice: ");
}

void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void handle_add_task(TaskList *list) {
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    
    clear_input_buffer();
    
    printf("\nEnter task title: ");
    if (!fgets(title, sizeof(title), stdin)) {
        printf("Error reading title.\n");
        return;
    }
    title[strcspn(title, "\n")] = '\0';
    
    if (strlen(title) == 0) {
        printf("Title cannot be empty.\n");
        return;
    }
    
    printf("Enter task description: ");
    if (!fgets(description, sizeof(description), stdin)) {
        printf("Error reading description.\n");
        return;
    }
    description[strcspn(description, "\n")] = '\0';
    
    int id = task_add(list, title, description);
    if (id > 0) {
        printf("\n✓ Task added successfully with ID: %d\n", id);
    } else {
        printf("\n✗ Failed to add task.\n");
    }
}

void handle_update_task(TaskList *list) {
    int id;
    char title[MAX_TITLE_LENGTH];
    char description[MAX_DESC_LENGTH];
    char status_str[20];
    
    printf("\nEnter task ID to update: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    Task *task = task_find_by_id(list, id);
    if (!task) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    
    printf("\nCurrent task details:\n");
    task_print(task);
    
    printf("\nEnter new title (press Enter to keep current): ");
    if (!fgets(title, sizeof(title), stdin)) {
        printf("Error reading title.\n");
        return;
    }
    title[strcspn(title, "\n")] = '\0';
    
    printf("Enter new description (press Enter to keep current): ");
    if (!fgets(description, sizeof(description), stdin)) {
        printf("Error reading description.\n");
        return;
    }
    description[strcspn(description, "\n")] = '\0';
    
    printf("Enter status (pending/in_progress/completed) [press Enter for current]: ");
    if (!fgets(status_str, sizeof(status_str), stdin)) {
        printf("Error reading status.\n");
        return;
    }
    status_str[strcspn(status_str, "\n")] = '\0';
    
    TaskStatus new_status = task->status;
    if (strlen(status_str) > 0) {
        new_status = task_string_to_status(status_str);
    }
    
    const char *new_title = strlen(title) > 0 ? title : NULL;
    const char *new_desc = strlen(description) > 0 ? description : NULL;
    
    if (task_update(list, id, new_title, new_desc, new_status)) {
        printf("\n✓ Task updated successfully.\n");
    } else {
        printf("\n✗ Failed to update task.\n");
    }
}

void handle_delete_task(TaskList *list) {
    int id;
    
    printf("\nEnter task ID to delete: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    Task *task = task_find_by_id(list, id);
    if (!task) {
        printf("Task with ID %d not found.\n", id);
        return;
    }
    
    printf("\nAre you sure you want to delete this task? (y/n): ");
    char confirm;
    scanf(" %c", &confirm);
    clear_input_buffer();
    
    if (confirm == 'y' || confirm == 'Y') {
        if (task_delete(list, id)) {
            printf("\n✓ Task deleted successfully.\n");
        } else {
            printf("\n✗ Failed to delete task.\n");
        }
    } else {
        printf("\nDelete cancelled.\n");
    }
}

void handle_view_task(TaskList *list) {
    int id;
    
    printf("\nEnter task ID to view: ");
    if (scanf("%d", &id) != 1) {
        printf("Invalid ID.\n");
        clear_input_buffer();
        return;
    }
    clear_input_buffer();
    
    Task *task = task_find_by_id(list, id);
    if (task) {
        task_print(task);
    } else {
        printf("Task with ID %d not found.\n", id);
    }
}

int main(void) {
    printf("Loading tasks from %s...\n", STORAGE_FILE);
    TaskList *list = storage_load(STORAGE_FILE);
    
    if (!list) {
        fprintf(stderr, "Failed to initialize task list.\n");
        return 1;
    }
    
    printf("Loaded %d task(s).\n", list->count);
    
    int choice;
    int running = 1;
    
    while (running) {
        print_menu();
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clear_input_buffer();
            continue;
        }
        
        switch (choice) {
            case 1:
                handle_add_task(list);
                break;
            case 2:
                task_print_all(list);
                break;
            case 3:
                handle_update_task(list);
                break;
            case 4:
                handle_delete_task(list);
                break;
            case 5:
                handle_view_task(list);
                break;
            case 6:
                printf("\nSaving tasks to %s...\n", STORAGE_FILE);
                if (storage_save(list, STORAGE_FILE)) {
                    printf("✓ Tasks saved successfully.\n");
                } else {
                    printf("✗ Failed to save tasks.\n");
                }
                printf("Goodbye!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    task_list_destroy(list);
    return 0;
}