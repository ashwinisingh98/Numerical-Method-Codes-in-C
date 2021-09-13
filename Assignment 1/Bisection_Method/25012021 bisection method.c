//Program for implementation of Bisection Method

#include<stdio.h>
#include<math.h>

#define eps 0.0005 //eps stands for epsilon
#define N 20

float func(float x)
{
    return ((x*x*x)-(x)-1);    
}

int main(void)
{
	int i;
	float a,b,mid;
    
    FILE *input, *out1, *out2;
    input=fopen("input/data.txt","r");
    out1=fopen("iterations/iteration.txt","w");
    out2=fopen("mid values/mid.txt","w");
	printf("Enter the brackets: ");
	fscanf(input,"%f %f",&a,&b);
	
	if(func(a)*func(b)<0)
	{   
	    printf("The required roots are\n");
	    printf("******************************************");
	   for (i=0;i<N;i++)
	   {
	       mid=(a+b)/2.0;
//	       printf("%f\n",mid);
//	       printf("func %f\n",fabs(func(mid)));
	       if(fabs(func(mid))<eps)
	       {
	           printf("The required root is : %f",mid);
	           break;
	       }
	       else
	       {
	           if(func(mid)*func(a)<0)
	           {
	               b=mid;
	           }
	           else if(func(mid)*func(b)<0)
	           {
	               a=mid;
	           }
	           fprintf(out1,"%d\n",i+1);
	           fprintf(out2,"%f\n",mid);
	       }
	   }
	   fprintf(out1,"%d\n",i+1);
	   fprintf(out2,"%f\n",mid);
	}
	else
	{
	    printf("Please enter feasible values of brackets");
	}
//	float res1,res2;
//	res1=func(a);
//	res2=func(b);
//	printf("%f %f",res1,res2);
	
	return 0;
}
