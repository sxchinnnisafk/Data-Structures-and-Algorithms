#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to define a Student Record
struct Student {
    int rollNumber;
    char name[50];
    float marks;
    struct Student* next;
};

// Global head pointer for the linked list
struct Student* head = NULL;

// Function Prototypes
void insertRecord();
void searchRecord();
void deleteRecord();
void displayRecords();

int main() {
    int choice;

    while (1) {
        printf("\n================================");
        printf("\n  STUDENT RECORD SYSTEM (LL)");
        printf("\n================================");
        printf("\n1. Insert Student Details");
        printf("\n2. Search Student Record");
        printf("\n3. Delete Student Record");
        printf("\n4. Display All Records");
        printf("\n5. Exit");
        printf("\n--------------------------------");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insertRecord(); break;
            case 2: searchRecord(); break;
            case 3: deleteRecord(); break;
            case 4: displayRecords(); break;
            case 5: 
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default: 
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

// 1. Function to insert student details at the beginning of the list
void insertRecord() {
    struct Student* newNode = (struct Student*)malloc(sizeof(struct Student));
    
    if (newNode == NULL) {
        printf("\nMemory allocation failed! System full.");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &newNode->rollNumber);
    printf("Enter Name: ");
    scanf(" %[^\n]s", newNode->name); // Reads string with spaces
    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = head;
    head = newNode;

    printf("\nSUCCESS: Record for '%s' inserted.", newNode->name);
}

// 2. Function to search for a specific record by Roll Number
void searchRecord() {
    int roll;
    struct Student* temp = head;

    if (head == NULL) {
        printf("\nLIST EMPTY: No records to search.");
        return;
    }

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    while (temp != NULL) {
        if (temp->rollNumber == roll) {
            printf("\n--- Record Found ---");
            printf("\nRoll No : %d", temp->rollNumber);
            printf("\nName    : %s", temp->name);
            printf("\nMarks   : %.2f", temp->marks);
            printf("\n--------------------");
            return;
        }
        temp = temp->next;
    }
    printf("\nNOT FOUND: Student with Roll Number %d does not exist.", roll);
}

// 3. Function to delete a record by Roll Number
void deleteRecord() {
    int roll;
    struct Student *temp = head, *prev = NULL;

    if (head == NULL) {
        printf("\nLIST EMPTY: Nothing to delete.");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    // Case: Record to be deleted is the head node
    if (temp != NULL && temp->rollNumber == roll) {
        head = temp->next;
        printf("\nDELETED: Record for Roll Number %d removed.", roll);
        free(temp);
        return;
    }

    // Search for the node to delete while keeping track of previous node
    while (temp != NULL && temp->rollNumber != roll) {
        prev = temp;
        temp = temp->next;
    }

    // Case: Roll Number not found in the list
    if (temp == NULL) {
        printf("\nNOT FOUND: Cannot delete non-existent record.");
        return;
    }

    // Unlink the node from the list
    prev->next = temp->next;
    printf("\nDELETED: Record for Roll Number %d removed.", roll);
    free(temp);
}

// 4. Function to display all records currently in the system
void displayRecords() {
    struct Student* temp = head;

    if (head == NULL) {
        printf("\nLIST EMPTY: No records found.");
        return;
    }

    printf("\n%-10s %-20s %-10s", "Roll No", "Name", "Marks");
    printf("\n-------------------------------------------");
    
    while (temp != NULL) {
        printf("\n%-10d %-20s %-10.2f", temp->rollNumber, temp->name, temp->marks);
        temp = temp->next;
    }
    printf("\n-------------------------------------------");
    printf("\nEnd of list.");
}
