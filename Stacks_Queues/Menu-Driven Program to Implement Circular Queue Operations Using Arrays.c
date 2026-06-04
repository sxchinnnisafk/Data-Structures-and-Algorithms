#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void insert() {
    int item;

    if ((front == (rear + 1) % MAX)) {
        printf("\nQueue Overflow! (Queue is Full)\n");
        return;
    }

    printf("Enter element to insert: ");
    if (scanf("%d", &item) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    if (front == -1) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = item;
    printf("Successfully inserted %d\n", item);
}

void cqdelete() {
    if (front == -1) {
        printf("\nQueue Underflow! (Queue is Empty)\n");
        return;
    }

    printf("Deleted element: %d\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

void cqdisplay() {
    int i;

    if (front == -1) {
        printf("\nQueue is Empty\n");
        return;
    }

    printf("\nQueue elements are: ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear) {
            break;
        }

        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Insert  2. Delete  3. Display  4. Exit");
        printf("\nEnter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                cqdelete();
                break;
            case 3:
                cqdisplay();
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
