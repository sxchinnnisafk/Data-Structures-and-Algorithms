#include <stdio.h>
#include <stdlib.h> 

int main()
{
    int *ptr;
    int n, i;

    printf("Enter number of Elements: ");
    if (scanf("%d", &n) != 1) return 1; 

    ptr = (int*)malloc(n * sizeof(int));

    if (ptr == NULL)
    {
        printf("Memory not allocated\n");
        exit(0);
    }
    else
    {
        printf("Memory successfully allocated using malloc\n");

        printf("Enter %d elements:\n", n);
        for (i = 0; i < n; ++i)
        {
            scanf("%d", ptr + i);
        }
        
        printf("The elements of Array are: ");
        for (i = 0; i < n; ++i)
        {
            printf("%d ", *(ptr + i)); 
        }
        printf("\n");
    }

    free(ptr);
    
    return 0;
}
