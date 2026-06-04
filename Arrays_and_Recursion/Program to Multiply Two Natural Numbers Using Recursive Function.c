#include <stdio.h>

int multiply(int a, int b) {
    if (b == 0) {
        return 0;
    }
    
    return a + multiply(a, b - 1);
}

int main() {
    int num1, num2, result;

    printf("Enter two natural numbers: ");
    scanf("%d %d", &num1, &num2);

    if (num1 < 0 || num2 < 0) {
        printf("Please enter natural numbers (positive integers).\n");
    } else {
        result = multiply(num1, num2);
        printf("Result of %d * %d = %d\n", num1, num2, result);
    }

    return 0;
}
