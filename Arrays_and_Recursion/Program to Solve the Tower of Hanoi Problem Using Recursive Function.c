#include <stdio.h>
#include <math.h>

void toh(int n, char source, char auxiliary, char destination);

int main() {
    int n;
    int moves;

    printf("Enter no of discs to be moved: ");
    scanf("%d", &n);

    toh(n, 'A', 'B', 'C');

    moves = pow(2, n);
    printf("\nIn total no of moves: %d\n", moves - 1);

    return 0;
}

void toh(int n, char source, char auxiliary, char destination) {

    if (n == 0) {
        return;
    }

    toh(n - 1, source, destination, auxiliary);

    printf("Move disc %d from %c to %c\n", n, source, destination);

    toh(n - 1, auxiliary, source, destination);
}
