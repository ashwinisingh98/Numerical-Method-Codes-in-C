//Program to calculate Factorial of a given number
#include <stdio.h>
int main() {
    int n, i;
    unsigned long long fact = 1;
    printf("\nEnter an integer: ");
    scanf("%d", &n);

    // shows error if the user enters a negative integer
    if (n < 0)
        printf("\nError! Factorial of a negative number doesn't exist.\n");
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
        printf("\nFactorial of %d = %llu\n", n, fact);
        printf("\n====================================\n");
    }

    return 0;
}
