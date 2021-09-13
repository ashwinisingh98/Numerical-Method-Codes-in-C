/*Implementation of Numerical Integration by Trapezoidal Rule.
 Coded by Ashwini Kumar Singh on 22-March-2021*/

#include<stdio.h>
#include<math.h>

double f(double x){
  return(1/(1+pow(x,2)));
}

int main(void){
    printf("\n*********************************************************************************\n");
    printf("\nImplementation of Numerical Integration by Trapezoidal Rule\n");
    printf("\nFor the Function : y = f(x)= 1/(1+pow(x,2))\n");
    printf("\nCoded by Ashwini Kumar Singh on 22-March-2021\n");
    printf("\n*********************************************************************************\n");

    int n,i;
    double x0,xn,h,x,sum=0,integral;
    printf("\nEnter values of x0,xn,n: ");
    scanf("%lf,%lf,%d",&x0,&xn,&n);
    h=(xn-x0)/n;

    for(i=1;i<n;i++){
        x=x0+i*h;
        sum=sum+f(x);
    }

    integral=(h/2)*(f(x0)+f(xn)+2*sum);
    printf("\nThe integral is: %lf\n",integral);
    return 0;
}
