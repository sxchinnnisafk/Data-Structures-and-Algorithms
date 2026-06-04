#include <stdio.h>
#include <stdlib.h>

#define max 3 // Changed from 5 to 3

int front = 0, rear = -1, count = 0;
int cq[max];

void cqinsert() {
    int ele;
    if (count == max) {
        printf("Queue Overflow\n\n");
        return;
    }
    printf("Enter the element to be inserted: ");
    scanf("%d", &ele);
    
    rear = (rear + 1) % max;
    cq[rear] = ele;
    count++;
}

void cqdelete() {
    if (count == 0) {
        printf("Queue Underflow\n\n");
        return;
    }
    printf("Element deleted is = %d\n\n", cq[front]);
    front = (front + 1) % max;
    count--;
}

void cqdisplay() {
    int j = front;
    if (count == 0) {
        printf("Queue is empty\n\n");
        return;
    }
    printf("Circular Queue content is:\n");
    for (int i = 1; i <= count; i++) {
        printf("%d\t", cq[j]);
        j = (j + 1) % max;
    }
    printf("\n\n");
}

int main() {
    int ch;
    while(1) {
        printf("1:Insert\t 2:Delete\t 3:Display\t 4:Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &ch) != 1) break;
        
        switch(ch) {
            case 1: cqinsert(); break;
            case 2: cqdelete(); break;
            case 3: cqdisplay(); break;
            case 4: exit(0);
            default: printf("Invalid choice\n\n"); break;
        }
    }
    return 0;
}
