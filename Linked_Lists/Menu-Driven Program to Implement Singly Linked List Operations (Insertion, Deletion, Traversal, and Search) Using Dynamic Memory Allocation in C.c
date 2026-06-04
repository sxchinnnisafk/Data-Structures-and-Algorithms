#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *first = NULL, *last = NULL;
int count = 0;

struct node *create_Node();
void insert_beg();
void insert_end();
void insert_random();
void traverse();
void delete_beg();
void delete_end();
void delete_random();
void search();
void freeList();

struct node *create_Node()
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter the data: ");

    if (scanf("%d", &newNode->data) != 1)
    {
        printf("Invalid input!\n");
        free(newNode);
        return NULL;
    }

    newNode->link = NULL;
    printf("NODE CREATED SUCCESSFULLY\n");

    return newNode;
}

void insert_beg()
{
    struct node *newNode = create_Node();

    if (newNode == NULL)
        return;

    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->link = first;
        first = newNode;
    }

    count++;
}

void insert_end()
{
    struct node *newNode = create_Node();

    if (newNode == NULL)
        return;

    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->link = newNode;
        last = newNode;
    }

    count++;
}

void insert_random()
{
    int pos, i = 1;

    if (first == NULL)
    {
        printf("List is empty. Inserting at beginning.\n");
        insert_beg();
        return;
    }

    printf("Enter the position (after which node): ");

    if (scanf("%d", &pos) != 1)
    {
        printf("Invalid input\n");
        return;
    }

    if (pos < 1 || pos > count)
    {
        printf("Invalid position!\n");
        return;
    }

    struct node *newNode = create_Node();

    if (newNode == NULL)
        return;

    struct node *temp = first;

    while (i < pos)
    {
        temp = temp->link;
        i++;
    }

    newNode->link = temp->link;
    temp->link = newNode;

    if (newNode->link == NULL)
    {
        last = newNode;
    }

    count++;
}

void traverse()
{
    struct node *temp = first;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("\nContents of SLL:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->link;
    }

    printf("NULL\n");
    printf("Number of nodes = %d\n", count);
}

void delete_beg()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = first;

    printf("Deleted element = %d\n", temp->data);

    first = first->link;

    if (first == NULL)
    {
        last = NULL;
    }

    free(temp);
    count--;

    printf("Node Deleted Successfully\n");
}

void delete_end()
{
    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    if (first->link == NULL)
    {
        printf("Deleted element = %d\n", first->data);

        free(first);

        first = last = NULL;
        count--;

        return;
    }

    struct node *temp = first;
    struct node *prev = NULL;

    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }

    prev->link = NULL;
    last = prev;

    printf("Deleted element = %d\n", temp->data);

    free(temp);
    count--;

    printf("Node Deleted Successfully\n");
}

void delete_random()
{
    int pos, i = 1;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter position to delete: ");

    if (scanf("%d", &pos) != 1)
    {
        printf("Invalid input\n");
        return;
    }

    if (pos < 1 || pos > count)
    {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1)
    {
        delete_beg();
        return;
    }

    struct node *temp = first;

    while (i < pos - 1)
    {
        temp = temp->link;
        i++;
    }

    struct node *delNode = temp->link;

    temp->link = delNode->link;

    if (delNode == last)
    {
        last = temp;
    }

    printf("Deleted element = %d\n", delNode->data);

    free(delNode);
    count--;

    printf("Node Deleted Successfully\n");
}

void search()
{
    int key, pos = 1;

    if (first == NULL)
    {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to search: ");

    if (scanf("%d", &key) != 1)
    {
        printf("Invalid input\n");
        return;
    }

    struct node *temp = first;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found at position %d\n", pos);
            return;
        }

        temp = temp->link;
        pos++;
    }

    printf("Element not found\n");
}

void freeList()
{
    struct node *temp;

    while (first != NULL)
    {
        temp = first;
        first = first->link;
        free(temp);
    }

    last = NULL;
    count = 0;
}

int main()
{
    int ch;

    printf("***** OPERATIONS ON SINGLY LINKED LIST *****\n");

    while (1)
    {
        printf("\n1. INSERT AT BEGINNING");
        printf("\n2. INSERT AT END");
        printf("\n3. INSERT AFTER POSITION");
        printf("\n4. TRAVERSE");
        printf("\n5. DELETE AT BEGINNING");
        printf("\n6. DELETE AT END");
        printf("\n7. DELETE AT POSITION");
        printf("\n8. SEARCH");
        printf("\n0. EXIT");

        printf("\nEnter your choice: ");

        if (scanf("%d", &ch) != 1)
        {
            printf("Invalid input\n");
            break;
        }

        switch (ch)
        {
            case 1:
                insert_beg();
                break;

            case 2:
                insert_end();
                break;

            case 3:
                insert_random();
                break;

            case 4:
                traverse();
                break;

            case 5:
                delete_beg();
                break;

            case 6:
                delete_end();
                break;

            case 7:
                delete_random();
                break;

            case 8:
                search();
                break;

            case 0:
                freeList();
                printf("Exiting Program...\n");
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }

    freeList();
    return 0;
}
