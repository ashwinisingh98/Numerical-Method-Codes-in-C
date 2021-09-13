//Program for Modified Euler Method
//Coded by Ashwini Kumar Singh on 12-Apr-2021

#include<stdio.h>
#include <math.h>


double F(double x,double y){
    double f=0.0;
    f=-y;
    return f;
}

int main(void)
{
  double x0,y0,y1,x1,y1_0,a,n,h,f,f1;
  int j,count,flag;
  printf("\nProgram for Modified Euler Method\n");
  printf("\nCoded by Ashwini Kumar Singh on 12-Apr-2021\n");
  printf("\nF(x,y)= dy/dx = -y\n");
  printf("\nEnter the value of x0,y0,h,n: ");
  scanf("%lf,%lf,%lf,%lf",&x0,&y0,&h,&n);

  for(x1=x0+h,j=1; x1<n+h; x1=x1+h,j++)
  {
    count=0;
    flag=0;
    f=F(x1-h,y0);
    y1_0 = y0 + (h * f);

    printf("\n\nx_%d=%lf \ty_%d=%lf \tf(x_%d,y_%d)=%lf \ty%d_0 = %lf \n\nx_%d = %lf \t",j-1,x1-h,j-1,y0,j-1,j-1,f,j,y1_0,j,x1);
     do
      {
        count++;
        f=F(x0,y0);
        f1=F(x1,y1_0);
        y1 = y0 + h/2 * ( f + f1);
        printf("F(x%d,y%d_%d)= %lf \ty%d_%d = %lf\n\n\t\t",j,j,count,F(x1,y1_0),j,count,y1);
        //printf("\neps = %lf\n",(x1*exp(-3.0)));
        if(fabs(y1-y1_0)<0.000001)
         {
          printf("\n\ny%d = %lf\n\n\n",j,y1);
          flag=1;
         }
        else
          y1_0 = y1;
      }while(flag!=1);
    y0 = y1;
  }
  printf("\ny(%lf) = %lf\n\n",n,y0);
  return 0;
}

