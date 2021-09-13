#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(int n)
{
    int i,j;
    float s=0.0;
    if(n==1){
        float wi=2.0,ji=2.0,ni=0.0,nj=0.0;
        for(j=1;j<=n;j++){
        for(i=1;i<=n;i++){
            //printf("%f\n",s);
            s=s+(wi*ji*(1.5+0.5*ni)*(2+nj)*(2.5+0.5*ni)*0.5);
        }
        }
    }
    else if(n==2){
        float eta[3],zee[3],w[3];
        w[1]=1.0,w[2]=1.0;
        zee[1]=-0.57735,zee[2]=0.57735;
        eta[1]=zee[1],eta[2]=zee[2];
        for(j=1;j<=n;j++){
            for(i=1;i<=n;i++){
                s=s+(w[i]*w[j]*(1.5+0.5*zee[i])*(2+eta[j])*(2.5+0.5*zee[i])*0.5);
                //printf("%f\n",(w[i]*w[j]*(1.5+0.5*zee[i])*(2+eta[j])*(2.5+0.5*zee[i])*0.5));
            }
        }
    }
    else if(n==3){
        float eta[4],zee[4],w[4];
        w[1]=0.555555,w[2]=0.888888,w[3]=0.555555;
        zee[1]=-0.774596,zee[2]=0.0,zee[3]=0.774596;
        eta[1]=zee[1],eta[2]=zee[2],eta[3]=zee[3];
        for(j=1;j<=n;j++){
            for(i=1;i<=n;i++){
                s=s+(w[i]*w[j]*(1.5+0.5*zee[i])*(2+eta[j])*(2.5+0.5*zee[i])*0.5);
                //printf("%f\n",(w[i]*w[j]*(1.5+0.5*zee[i])*(2+eta[j])*(2.5+0.5*zee[i])*0.5));
            }
        }
    }

    return s;
}

int main(void)
{
    int n;
    float res;
    printf("Enter no. of Guass Points(1,2 or 3): ");
    scanf("%d",&n);

    if(n==1){
        res=f(1);
        //printf("c1\n");
    }
    else if(n==2){
        res=f(2);
    }
    else if(n==3){
        res=f(3);
    }
    else{
        printf("Please enter correct value of n");
        return 0;
    }
    printf("\nThe value of integral according to %d point Guass Quadrature Rule if %f\n",n,res);
    return 0;
}
