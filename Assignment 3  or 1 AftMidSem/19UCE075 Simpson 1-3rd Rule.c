/*Implementation of Numerical Integration by Simpson 1/3rd Rule.
 Coded by Ashwini Kumar Singh on 22-March-2021*/

#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
    return(1/(1+pow(x,2)));
}

int main(void){
    printf("\n************************************************************************************\n");
    printf("\nImplementation of Numerical Integration by Simpson 1/3rd Rule\n");
    printf("\nFor the Function : y = f(x)= 1/(1+pow(x,2))\n");
    printf("\nCoded by Ashwini Kumar Singh on 22-March-2021\n");
    printf("\n************************************************************************************\n");

    int i,n;
    float x0,xn,h,y[20],so=0.0,se=0.0,ans,x[20];
    printf("\n Enter values of x0,xn,h: ");
    scanf("%f,%f,%f",&x0,&xn,&h);

    n=floor((xn-x0)/h);
    if(n%2==1){
        n=n+1;
    }

    h=(xn-x0)/n;

    printf("\nRefined value of n and h are: %d  %f\n",n,h);
    printf("\n Y[i] values \n=================\n");
    for(i=0; i<=n; i++){
        x[i]=x0+i*h;
        y[i]=f(x[i]);
        printf("\nY[%d] = %f\n",i,y[i]);
    }

    for(i=1; i<n; i++){
        if(i%2==1){
            so=so+y[i];
        }
        else{
            se=se+y[i];
        }
    }

    ans=(h/3)*(y[0]+y[n]+4*so+2*se);

    printf("\nFinal integration is %f",ans);
    return 0;
}
