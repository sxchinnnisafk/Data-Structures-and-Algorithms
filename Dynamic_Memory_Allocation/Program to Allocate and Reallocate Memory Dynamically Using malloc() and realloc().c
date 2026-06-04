#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *ptr;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    ptr = (int*)malloc(n * sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    printf("Enter %d integers.\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Elements are: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    ptr = (int*)realloc(ptr, (n + 3) * sizeof(int));
    if (ptr == NULL) {
        return 1;
    }

    printf("Enter 3 more elements: \n");
    for (i = n; i < n + 3; i++) {
        scanf("%d", &ptr[i]);
    }

    printf("Updated elements are: ");
    for (i = 0; i < n + 3; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    return 0;
}
