#include <stdio.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, i;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    int empIDs[n];
    printf("Enter %d Employee IDs:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &empIDs[i]);
    }

    printf("\nOriginal Employee IDs: ");
    display(empIDs, n);

    bubbleSort(empIDs, n);

    printf("Sorted Employee IDs (Ascending): ");
    display(empIDs, n);

    return 0;
}
