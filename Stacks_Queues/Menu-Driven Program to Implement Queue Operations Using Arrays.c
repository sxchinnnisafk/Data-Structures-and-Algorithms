#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int rear = -1;
int front = 0;
void enqueue();
void dequeue();
void display();
int main()
{
    int choice;

    while (1)
    {
        printf("\n1. Insert element to queue\n");
        printf("2. Delete element from queue\n");
        printf("3. Display all elements of queue\n");
        printf("4. Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
    switch (choice)
        {
            case 1: enqueue();
                    break;
            case 2: dequeue();
                    break;
            case 3: display();
                    break;
            case 4: exit(0);
            default: printf("Wrong choice\n");
        }
    }
}

void enqueue()
{
    int add_item;
if (rear == MAX - 1)
    {
        printf("Queue Overflow\n");
        return;
    }
   printf("Insert the element in queue : ");
    scanf("%d", &add_item);
     rear = rear + 1;
    queue[rear] = add_item;
}

void dequeue()
{
    if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Element deleted from queue is : %d\n", queue[front]);
    front = front + 1;
}

void display()
{
    int i;
 if (front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
printf("Contents of Queue are :\n");
 for (i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
printf("\n");
}

