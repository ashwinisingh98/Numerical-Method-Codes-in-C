// program to find factorial of a number
#include<stdio.h>
int factorial(int n)
{
    if(n==0)
    {
        return (1);
    }
    else
    {
        return (n*factorial(n-1));
    }
}
int main()
{
    int n;
    printf("enter the number you want to find factorial of:\t");
    scanf("%d",&n);
    printf("required factorial of %d is\t%d\n",n,factorial(n));
}