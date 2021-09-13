//**************************************************
//Program for implementation of Secant Method
//Coded by Ashwini K. Singh on 01-Feb-2021
//**************************************************

#include<stdio.h>   // Inclusion of the input-output header file
#include<math.h>    // Inclusion of the math header file

//*******EVALUATION OF THE FUNCTION
float f(float x)
{
    return ((x*x*x)-2*x-5);
}
//*******END OF FUNCTION f

float df(float x_,float x)
{
    return (f(x)-f(x_))/(x-x_);
}
//*******END OF FUNCTION df

//*************STARTING MAIN FUNCTION*********
int main(void)
{
    int i, N;                                   //Variable declaration
    float h, x_,x0, x1, e;                         //Variable declaration

    printf("\nF(x) = ((x*x*x)-x-1)\n");

    FILE *input, *output;
    input=fopen("inSecant.txt","r");
    output=fopen("outSecant.tsv","w");

    printf("\nPlease ensure x_ < x0\n");
    // Reading inputs from the input file
    fscanf(input,"%f,%f,%f,%d", &x_, &x0, &e, &N);

    // Displaying inputs read from the input file on the console
    printf("\nValues of x_, x0,  allowed error and max iterations read from 'inSecant.txt' are: %f, %f, %f, %d\n",x_,x0,e,N);
    // Writing the column-headers in the output file
    fprintf(output,"Iteration\tx_\tx0\tx1\tabs(h)\n");
    printf("\nItrn\t\tx_\tx0\t\tf(x0)\t\tdf(x_,x0)\th\t\tx1\t\tabs(h)\n\n");
    for (i=1; i<=N; i++)
    {
        h=f(x0)/df(x_,x0);
        x1=x0-h;
        fprintf(output,"%d\t%9.6f\t%9.6f\t%9.6f\t%9.6f\n", i, x_, x0, x1,fabs(h));   // Writing the outputs in the output file

        printf("%d\t%9.6f\t%9.6f\t%9.6f\t%9.6f\t%9.6f\t%9.6f\t%9.6f\n", i, x_, x0,f(x0),df(x_,x0),h, x1,fabs(h));
        if (fabs(h) < e)
        {
            printf("\nAfter %d iterations, root = %9.6f\n", i, x1);    // Displaying the final output on console
            return 0;
        }
        x_=x0;
        x0=x1;

    }
    printf("\nThe required solution does not converge or iterations are insufficient\n");
    return 1;
}
//****************END OF MAIN FUNCTION**********

