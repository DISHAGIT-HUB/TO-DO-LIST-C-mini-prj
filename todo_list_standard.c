
#include <stdio.h>
#include <string.h>
#define MAX_TASKS 50
#define MAX_LENGTH 100

char tasks[MAX_TASKS][MAX_LENGTH];
int taskCount = 0;

void addTask() {
    if (taskCount < MAX_TASKS) {
        printf("Enter task: ");
        getchar();
        fgets(tasks[taskCount], MAX_LENGTH, stdin);
        tasks[taskCount][strcspn(tasks[taskCount], "\n")] = 0;
        taskCount++;
        printf("Task added successfully!\n");
    } else {
        printf("Task list is full!\n");
    }
}

void viewTasks() {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        printf("\n--- To-Do List ---\n");
        for (int i = 0; i < taskCount; i++) {
            printf("%d. %s\n", i + 1, tasks[i]);
        }
    }
}

void deleteTask() {
    int taskNumber;
    if (taskCount == 0) {
        printf("No tasks to delete.\n");
        return;
    }
    viewTasks();
    printf("Enter task number to delete: ");
    scanf("%d", &taskNumber);
    if (taskNumber < 1 || taskNumber > taskCount) {
        printf("Invalid task number!\n");
    } else {
        for (int i = taskNumber - 1; i < taskCount - 1; i++) {
            strcpy(tasks[i], tasks[i + 1]);
        }
        taskCount--;
        printf("Task deleted successfully!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\n--- To-Do List Menu ---\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Delete Task\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                deleteTask();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
