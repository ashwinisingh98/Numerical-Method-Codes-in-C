//Program for Modified Euler Method
//Coded by Ashwini Kumar Singh on 20-Apr-2021

#include<stdio.h>
#include <math.h>


double fn(double x,double y){
    double f;
    f=(y-x)/(y+x);
    return f;
}

int main(void)
{
  int i=0,j=0,n;
  double x0,y0,h,xn,y,x1;

  printf("\nProgram for Modified Euler Method\n");
  printf("\nCoded by Ashwini Kumar Singh on 12-Apr-2021\n");
  printf("\nF(x,y)= dy/dx = -y\n");

  printf("\nEnter the value of x0,y0,h,xn: ");
  scanf("%lf,%lf,%lf,%lf",&x0,&y0,&h,&xn);

  n=(xn-x0)/h;
  printf("\nThe value of n = %d \n",n);

  double y1[n];

  printf("\nThe required solution is:\nItr(i)\tx0\t\ty0\t\tfn(x0,y0)\ty(i+1)0\t\tfn(x0+h,y1[i])\t(h/2)*(fn0+fn(x0+h,y1[i]))\ty(i+1)\n");

  while(x0<xn)
  {

      y1[0]=y0+fn(x0,y0)*h;
      //printf("\n%lf",y1[0]);
      y=y1[0];
      printf("\n%d\t%lf\t%lf\t%lf\t%lf\t",j,x0,y0,fn(x0,y0),y);
      for(i=0;i<10;++i)
      {
          y1[i+1]=y0+(h/2)*(fn(x0,y0)+fn(x0+h,y1[i]));
          y=y1[i+1];
          printf("%lf\t%lf\t\t\t%lf\n\n\t\t\t\t\t\t\t\t\t",fn(x0+h,y1[i]),(h/2)*(fn(x0,y0)+fn(x0+h,y1[i])),y);
          if(fabs(y1[i]-y1[i+1])<0.0001)
            break;
      }

      x0+=h;
      y0=y;
      ++j;
  }
  printf("\nThe required solution is: y(%lf) = %lf\n",xn,y);
  return 0;
}

