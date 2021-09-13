//Program for Euler Method
//Coded by Ashwini Kumar Singh on 12-Apr-2021

#include<stdio.h>
float fun(float x,float y)
{
    float f;
    f=(y-x)/(y+x);
    return f;
}


int main(void)
{
    float a,b,x,y,h,t,k;
    printf("\nProgram for Modified Euler Method\n");
    printf("\nCoded by Ashwini Kumar Singh on 12-Apr-2021\n");
    printf("\nF(x,y)= dy/dx = -y\n");
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%f,%f,%f,%f",&a,&b,&h,&t);
    x=a;
    y=b;
    printf("\nSolution using Euler method: \n");
    printf("\n  xi\t\t  yi\t\t fun(xi,yi)\t y(i+1)\n");
    while(x<t)
    {
        k=h*fun(x,y);
        printf("%f\t%f\t%f\t",x,y,fun(x,y));
        y=y+k;
        printf("%f\n",y);
        x=x+h;
    }

    printf("\nHence y(%f) = %f\n",t,y);
    return 0;
}
