#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void insert() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("\nStack Overflow! Memory allocation failed.");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("Inserted %d successfully.", value);
}

void delete() {
    struct Node* temp;
    if (top == NULL) {
        printf("\nStack Underflow! Nothing to delete.");
    } else {
        temp = top;
        printf("Deleted element: %d", top->data);
        top = top->next;
        free(temp);
    }
}

void peek() {
    if (top == NULL) {
        printf("\nStack is empty.");
    } else {
        printf("Top element is: %d", top->data);
    }
}

void display() {
    struct Node* temp;
    if (top == NULL) {
        printf("\nStack is empty.");
    } else {
        printf("\nStack elements (Top to Bottom):\n");
        temp = top;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n\n--- Linked List Stack Operations ---");
        printf("\n1. Insert (Push)\n2. Delete (Pop)\n3. Peek\n4. Display\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: exit(0);
            default: printf("Invalid choice!");
        }
    }
    return 0;
}
