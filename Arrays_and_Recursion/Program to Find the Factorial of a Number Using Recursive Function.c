#include <stdio.h>

int fact(int n);

int fact(int n)
{
    // Base case
    if (n == 0)
        return 1;
    else
        return n * fact(n - 1);
}

int main()
{
    int n, factorial;

    printf("Enter a number: ");
    scanf("%d", &n);

    factorial = fact(n);

    printf("Factorial of given number is: %d", factorial);

    return 0;
}
