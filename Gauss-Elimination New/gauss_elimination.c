 /* ***************************************************************
  *	Program to solve a system of linear simultaneous equations 	  *
  *	using Gauss Elimination method (without pivoting)			  *
  *	Function: gauss_elemination									  *
  * 	Written by: Dr. Surajit Das, Date: 09/08/2013		      *
  *****************************************************************/
#include<stdio.h>
#define N 3		/*	N: Order of the coefficient matrix	*/

//************ Function Prototype	**************************

double gauss_elemination(double a[N][N],
					double b[N],double c[N]);

//************ Main Function	**********************************

int main(void)
{
	double a[N][N],b[N],x[N];
	int i,j;

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

	gauss_elemination(a,b,x);

	fprintf(fp_out_2,"SOLUTION\nVECTOR\n********\n");

	for(i=0;i<N;i++)
	{
		fprintf(fp_out_2,"%7.4lf\n\n",x[i]);
		for(j=0;j<N;j++)
		{
			fprintf(fp_out_1,"%7.2lf",a[i][j]);
		}
        fprintf(fp_out_1,"\n\n");
	}

	fclose(fp_in_1);
	fclose(fp_in_2);
	fclose(fp_out_1);
	fclose(fp_out_2);

	return 0;
}

 /***************************************************************
  *		Function: gauss_elemination			                    *
  ***************************************************************/

	double gauss_elemination(double a[N][N],
						double b[N],double c[N])

//******		Forward Elimination		****************
{
	int i,j,k;
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

//******		   Back Substitution		   *************

	c[N-1]=b[N-1]/a[N-1][N-1];
	for(i=N-2;i>=0;i--)
	{
		factor=(1/a[i][i]);
		c[i]=b[i]*factor;
		for(j=N-1;j>i;j--)
		{
			c[i]-=a[i][j]*c[j]*factor;
		}
	}

//******		End of Back Substitution		************
	return 0;
}
