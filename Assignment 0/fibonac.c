#include <stdio.h>
int fibo_recursive(int n)
{
        if (n <= 1)
        {
            return n;
        }
        else
        {
            return (fibo_recursive(n-1) + fibo_recursive(n-2));
        }
}

int fibo_iterative(int n)
{
    int a = 0;
    int b = 1;
    for(int i=0; i<n-1; i++)
    {
        b = a+b;
        a = b-a;
    }
    return b;
}

int main()
{
    int a;
    printf("enter the number upto which you want fibonacci value\n");
    scanf("%d", &a);
    
    printf("the fibonacci value is from iterative appraoch is \t %d\n", fibo_iterative(a));
    printf("the fibonacci value is from recursive approach is \t %d", fibo_recursive(a));
    return 0;
}
// its faster and easier to use iterative method in fibonacci series for bigger inputs