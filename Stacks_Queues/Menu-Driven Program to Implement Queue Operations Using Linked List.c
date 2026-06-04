#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void insert() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("\nQueue Overflow! Memory allocation failed.");
        return;
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);
    
    newNode->data = value;
    newNode->next = NULL;

    if (front == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode; 
    }
    printf("Inserted %d successfully.", value);
}

void delete() {
    struct Node* temp;
    if (front == NULL) {
        printf("\nQueue Underflow! Nothing to delete.");
    } else {
        temp = front;
        printf("Deleted element: %d", front->data);
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void peek() {
    if (front == NULL) {
        printf("\nQueue is empty.");
    } else {
        printf("Front element is: %d", front->data);
    }
}

void display() {
    struct Node* temp;
    if (front == NULL) {
        printf("\nQueue is empty.");
    } else {
        printf("\nQueue elements (Front to Rear):\n");
        temp = front;
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
        printf("\n\n--- Linked List Queue Operations ---");
        printf("\n1. Insert (Enqueue)\n2. Delete (Dequeue)\n3. Peek\n4. Display\n5. Exit");
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
