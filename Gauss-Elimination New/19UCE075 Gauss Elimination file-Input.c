/*Implementation of solution of system of linear equations by Gauss Elimination method.
 Coded by Ashwini Kumar Singh on 10-Feb-2021*/

#include<stdio.h>
#include<math.h>

int main(void) {
    int i,j,k,N;
    printf("\n************************************************************************************\n");
    printf("\nImplementation of solution of system of linear equations by Gauss Elimination method\n");
    printf("\nCoded by Ashwini Kumar Singh on 10-Feb-2021\n");
    printf("\n************************************************************************************\n");
    printf("\nEnter the value of n \n");
    scanf("%d",&N);

    double a[N][N],b[N],x[N];

    FILE *fp_in_1=fopen("a_matrix.txt","r");
	FILE *fp_in_2=fopen("b_matrix.txt","r");
	FILE *fp_out_1=fopen("upper_triangular.txt","w");
	FILE *fp_out_2=fopen("solution.txt","w");

	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			fscanf(fp_in_1,"%lf",&a[i][j]);
		}
		fscanf(fp_in_2,"%lf",&b[i]);
	}

    printf("\nThe matrices read from a_matrix.txt and b_matrix.txt are:\n\n\t\tMatrix - A\t\t\t\tMatrix - B\n\n");
    for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			printf("%lf\t",a[i][j]);
		}
		printf("\t%lf\n",b[i]);
	}

	/*Function: gauss_elimination*/
//Forward Elimination
	double factor;
	for(i=0;i<N-1;i++)
	{
		for(j=1;i+j<N;j++)
		{
			factor=-a[i+j][i]/a[i][i];
			b[i+j]+=b[i]*factor;
			for(k=0;k<N;k++)
			{
				a[i+j][i+k]+=a[i][i+k]*factor;
			}
		}
	}
//Back Substitution
	x[N-1]=b[N-1]/a[N-1][N-1];
	for(i=N-2;i>=0;i--)
	{
		factor=(1/a[i][i]);
		x[i]=b[i]*factor;
		for(j=N-1;j>i;j--)
		{
			x[i]-=a[i][j]*x[j]*factor;
		}
	}

	fprintf(fp_out_2,"*****************\nSOLUTION VECTOR\n*****************\n");
    printf("\n*****************\t\t*****************\nSOLUTION VECTOR\t\t\tUPPER TRI-MATRIX\n*****************\t\t*****************\n");
	for(i=0;i<N;i++)
	{
		fprintf(fp_out_2,"%7.4lf\n\n",x[i]);
		printf("%7.4lf\t\t\t",x[i]);
		for(j=0;j<N;j++)
		{
			fprintf(fp_out_1,"%7.2lf",a[i][j]);
			printf("%7.2lf\t",a[i][j]);
		}
        fprintf(fp_out_1,"\n\n");
        printf("\n\n");
	}

    fclose(fp_in_1);
	fclose(fp_in_2);
	fclose(fp_out_1);
	fclose(fp_out_2);

	printf("\n************************************************************************************\n");
    printf("\nImplementation of solution of system of linear equations by Gauss Elimination method\n");
    printf("\nCoded by Ashwini Kumar Singh on 10-Feb-2021\n");
    printf("\n************************************************************************************\n");

    return 0;
}
