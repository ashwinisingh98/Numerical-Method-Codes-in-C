/*Implementation of solution of system of linear equations by Gauss-Jacobi's iteration method.
 Coded by Ashwini Kumar Singh on 10-Feb-2021*/

#include<stdio.h>
#include<math.h>

int main() {
    int i,j,m,n,itrn;

    printf("\n************************************************************************************\n");
    printf("\nImplementation of solution of system of linear equations by Gauss-Jacobi's iteration method\n");
    printf("Coded by Ashwini Kumar Singh on 10-Feb-2021\n");
    printf("\n************************************************************************************\n");

    FILE *fp_in_1=fopen("a_matrix.txt","r");
	FILE *fp_in_2=fopen("b_matrix.txt","r");
	FILE *output=fopen("outGaussSeidelItr.tsv","w");

	printf("\nEnter the value of n :");
	scanf("%d",&n);

	printf("\nEnter the number of iterations : ");
    scanf("%d",&itrn);

    double a[n][n],b[n],x[n],c[n];

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			fscanf(fp_in_1,"%lf",&a[i][j]);
		}
		fscanf(fp_in_2,"%lf",&b[i]);
	}

    printf("\nThe matrices read from a_matrix.txt and b_matrix.txt are:\n\n\t\tMatrix - A\t\t\t\tMatrix - B\n\n");
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf\t",a[i][j]);
		}
		printf("\t%lf\n",b[i]);
	}

    fprintf(output,"\nIteration");
    for(i=1;i<=n;i++)
        {
            fprintf(output,"\tJx%d",i);
        }

    m=1;
    do{
    for(i=0;i<n;i++) {
        c[i]=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                c[i]=c[i]-a[i][j]*x[j];
            }
        }
    }
    for(i=0;i<n;i++) {
        x[i]=c[i]/a[i][i];
    }

    printf("\n%d\t:\t",m);
    fprintf(output,"\n%d\t",m);
    for(i=0;i<n;i++)
        {
            printf("x(%d) = %f\t",i+1,x[i]);
            fprintf(output,"%f\t",x[i]);
        }
    m++;
    }while(m<=itrn);

    printf("\n\nThe Solution is : \n");
    for(i=0;i<n;i++)
        {
            printf("\nx(%d) = %f",i,x[i]);
        }
}
