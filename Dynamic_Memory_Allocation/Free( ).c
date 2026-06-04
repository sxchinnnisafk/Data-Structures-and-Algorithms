#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    int *m_ptr, *c_ptr;
    int i;

    m_ptr = (int*) malloc(n * sizeof(int));
    c_ptr = (int*) calloc(n, sizeof(int));

    if (m_ptr == NULL || c_ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Malloc values: ");
    for (i = 0; i < n; i++) {
        printf("%d ", m_ptr[i]);
    }
    
    printf("\nCalloc values: ");
    for (i = 0; i < n; i++) {
        printf("%d ", c_ptr[i]);
    }

    free(m_ptr);
    free(c_ptr);
    m_ptr = NULL;
    c_ptr = NULL;

    printf("\n\nMemory successfully freed.\n");

    return 0;
}
