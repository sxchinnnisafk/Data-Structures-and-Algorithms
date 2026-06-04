#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, *temp;
    int n = 5, i;

    ptr = (int *)calloc(n, sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Memory successfully allocated using calloc\n");

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The elements of the array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    n = 10;

    temp = (int *)realloc(ptr, n * sizeof(int));

    if (temp == NULL)
    {
        printf("Memory re-allocation failed\n");
        free(ptr);
        return 1;
    }

    ptr = temp;

    printf("Memory successfully re-allocated using realloc\n");

    printf("Enter %d more elements: ", n - 5);
    for (i = 5; i < n; i++)
    {
        scanf("%d", &ptr[i]);
    }

    printf("The updated array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);

    return 0;
}
