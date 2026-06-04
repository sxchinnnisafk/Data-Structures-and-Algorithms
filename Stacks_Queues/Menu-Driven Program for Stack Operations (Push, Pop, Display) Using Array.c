#include <stdio.h>
#include <stdlib.h> // Required for exit(0)

#define MAX 5 // Maximum size of the stack

int stack[MAX];
int top = -1;

// Function to add an element to the stack
void push() {
    int val;
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        printf("Enter value: ");
        scanf("%d", &val);
        stack[++top] = val;
    }
}

// Function to remove an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Popped: %d\n", stack[top--]);
    }
}

// Function to display the stack elements
void display() {
    if (top == -1) {
        printf("Stack Empty\n");
    } else {
        printf("Stack elements: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n1.Push 2.Pop 3.Display 4.Exit: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                push(); 
                break;
            case 2: 
                pop(); 
                break;
            case 3: 
                display(); 
                break;
            case 4: 
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
