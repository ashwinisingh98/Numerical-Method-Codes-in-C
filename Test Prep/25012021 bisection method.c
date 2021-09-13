//Program for implementation of Bisection Method
//Coded by Ashwini Kumar Singh on 25/Jan/2021

#include<stdio.h>
#include<math.h>

#define eps 0.0005 //eps stands for epsilon
#define N 20

float func(float x)
{
    return ((x*x*x)-3);
}

int main(void)
{
	int i;
	float a,b,mid;

    FILE *input, *out1;
    input=fopen("inBisection.txt","r");
    out1=fopen("outBisection.tsv","w");
	fscanf(input,"%f %f",&a,&b);
	printf("\nF(x) = (x*x*x)-3\n");
    printf("\nThe values of the brackets read from inBisection.txt are : %f\t%f\n\n",a,b);
	if(func(a)*func(b)<0)
	{
	    printf("Itrn\t\ta\tb\t\tMid-Value\tF(a)\t\tF(b)\t\t|F(Mid-Value)|\n\n");
	    for (i=0;i<N;i++)
	   {
	       mid=(a+b)/2.0;
	       printf("%d\t%f\t%f\t%f\t%f\t%f\t%f\n",i+1,a,b,mid,func(a),func(b),fabs(func(mid)));
	       if(fabs(func(mid))<eps)
	       {
	           printf("\nThe required root is : %f",mid);
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
	           fprintf(out1,"%d\t%f\n",i+1,mid);
	       }
	   }
	   fprintf(out1,"%d\t%f\n",i+1,mid);
	}
	else
	{
	    printf("Please enter feasible values of brackets");
	}

	fclose(input);
	fclose(out1);
	return 0;
}
