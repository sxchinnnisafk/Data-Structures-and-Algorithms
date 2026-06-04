//C Program to implement stack operations using arrays.

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push();
void pop();
void display();
int isFull();
int isEmpty();

int main() {
    int choice;

    while (1) {
        printf("\n--- Stack Operations ---");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("\nInvalid choice! Please try again.");
        }
    }
    return 0;
}

int isFull() {
    if (top == MAX - 1)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void push() {
    int value;
    if (isFull()) {
        printf("\nStack Overflow! Cannot push more elements.");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;
        stack[top] = value;
        printf("Inserted %d successfully.", value);
    }
}

void pop() {
    if (isEmpty()) {
        printf("\nStack Underflow! No elements to pop.");
    } else {
        printf("Popped element: %d", stack[top]);
        top--;
    }
}

void display() {
    if (isEmpty()) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack elements are:\n");
        for (int i = top; i >= 0; i--) {
            printf("%d\n", stack[i]);
        }
    }
}

