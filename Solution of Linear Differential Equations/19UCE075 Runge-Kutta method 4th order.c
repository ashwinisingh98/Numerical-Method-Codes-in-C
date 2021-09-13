//Program for Runge-Kutta method 4th order
//Coded by Ashwini Kumar Singh on 20-Apr-2021

#include<stdio.h>
#include <math.h>


double fn(double x,double y){
    double f=0.0;
    f=-y;
    return f;
}

int main(void)
{
  double x0,y0,h,x,y,xn,k1,k2,k3,k4,k;
  int i,n;

  printf("\nProgram for Modified Euler Method\n");
  printf("\nCoded by Ashwini Kumar Singh on 20-Apr-2021\n");
  printf("\nF(x,y)= dy/dx = -y\n");

  printf("\nEnter the value of x0,y0,h,xn: ");
  scanf("%lf,%lf,%lf,%lf",&x0,&y0,&h,&xn);

  x=x0;
  y=y0;
  n=(xn-x0)/h;
  printf("\nThe value of n: %d",n);

  printf("\nThe required solution is:\n\tItr(i)\tx\t\ty\t\tk1\t\tk2\t\tk3\t\tk4\t\t\k\ty(i+1)\n");

  for(i=0;i<n;++i)
  {
      k1=fn(x,y);
      k2=fn(x+0.5*h,y+0.5*k1*h);
      k3=fn(x+0.5*h,y+0.5*k2*h);
      k4=fn(x+h,y+k3*h);
      k=(h/6)*(k1+2*k2+2*k3+k4);
      y+=k;

      printf("\n\t%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,x,y-k,k1,k2,k3,k4,k,y);
      x+=h;
  }
  printf("\nThe required solution is: y(%lf) = %lf\n",xn,y);
  return 0;
}

