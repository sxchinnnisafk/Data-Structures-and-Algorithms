#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue_array[MAX];
int rear = -1;
int front = -1;

void enqueue();
void dequeue();
void display();

int main() {
    int choice;
    
    while (1) {
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a valid number.\n");
            while(getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Wrong choice! Please select 1-4.\n");
        }
    }
    return 0;
}

void enqueue() {
    int add_item;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot add more elements.\n");
    } else {
        if (front == -1) { 
            front = 0;
        }
        printf("Enter the element to insert: ");
        scanf("%d", &add_item);
        rear++;
        queue_array[rear] = add_item;
        printf("Inserted %d successfully.\n", add_item);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Nothing to delete.\n");
        front = rear = -1; 
    } else {
        printf("Element deleted from queue is: %d\n", queue_array[front]);
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is currently empty.\n");
    } else {
        printf("Queue contents: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue_array[i]);
        }
        printf("\n");
    }
}
