/*Implementation of solution of  linear equations by Gauss-Seidel's iteration method.
 Coded by Ashwini Kumar Singh on 10-Feb-2021*/

#include<stdio.h>
#include<math.h>

int main() {
    int i,j,m,n,itrn;

    printf("\n************************************************************************************\n");
    printf("\nImplementation of solution of system of linear equations by Gauss-Seidel's iteration method\n");
    printf("\nCoded by Ashwini Kumar Singh on 10-Feb-2021\n");
    printf("\n************************************************************************************\n");

    printf("\nEnter the no. of unknown(n) : \n");
    scanf("%d",&n);

    float x[n],a[n][n],b[n],c;

    printf("\nEnter the number of iterations : \n");
    scanf("%d",&itrn);

    printf("\nEnter the right hand side constants : \n");
    for(i=0;i<n;i++) {
        scanf("%f",&b[i]);
    }

    printf("\nEnter the coefficients row wise : \n");
    for(i=0;i<n;i++) {
        x[i]=0;
        for(j=0;j<n;j++) {
            scanf("%f",&a[i][j]);
        }
    }

    FILE *output;
    output=fopen("outGaussSeidelItr.tsv","w");

    fprintf(output,"\nIteration");
    for(i=1;i<=n;i++)
        {
            fprintf(output,"\tJx%d",i);
        }

    for(m=1;m<=itrn;m++)
    {
       for(i=0;i<n;i++)
        {
        c=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                c=c-a[i][j]*x[j];
            }
        }
        x[i]=c/a[i][i];
        }

        printf("\n%d\t:\t",m);
        fprintf(output,"\n%d\t",m);
        for(i=0;i<n;i++)
            {
                printf("x(%d) = %f\t",i+1,x[i]);
                fprintf(output,"%f\t",x[i]);
            }

    }

    printf("\n\nThe Solution is : \n");
    for(i=0;i<n;i++)
        {
            printf("\nx(%d) = %f",i+1,x[i]);
        }
}
