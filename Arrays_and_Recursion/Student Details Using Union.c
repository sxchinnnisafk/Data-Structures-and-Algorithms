#include <stdio.h>
#include <string.h>

union student {
    int roll_no;
    float marks;
    char name[20];
};

int main() {
    union student s1;

    printf("--- Union Demonstration ---\n");
    

    strcpy(s1.name, "Sachin T");
    printf("Name: %s\n", s1.name);


    s1.marks = 93.8;
    printf("Marks: %.1f\n", s1.marks);


    s1.roll_no = 21;
    printf("Roll No: %d\n", s1.roll_no);

    return 0;
}
