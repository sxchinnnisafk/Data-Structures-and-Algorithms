#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)          // Base case
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("GCD is: %d", gcd(a, b));

    return 0;
}
