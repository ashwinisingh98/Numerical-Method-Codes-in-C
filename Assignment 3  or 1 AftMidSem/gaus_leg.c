/* To compute the integral of a function using Gauss quadrature method */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* define paramter constants */
#define pi 4*atan(1.0)
#define EPS 3.0e-11

/* declare the routine that compute the points at which the 
function value to be evaluated and the corresponding weights */

void gauleg(float x1, float x2, float x[], float w[], int n);

main()
{
/* variable declarations */
	FILE *fp1;
	int i,j,Npoints,n;
/* also specify the upper and lower limit of the integral */
	float *w,*x,upper_lmt=1.0,lower_lmt=.0,S;
        char fname[20];
       printf("\n Here, upper limit=%f; lower limit=%f\n",upper_lmt,lower_lmt);
/* Read from the screen the number of points at which the function has to be evaluated */
       printf("\n Enter no of gausleg pts you want:");
       scanf("%d",&Npoints);
/* Allocate memory to store the abscissa and the corresponding weigths */
        w=(float *)malloc((Npoints+2)*sizeof(float));
        x=(float *)malloc((Npoints+2)*sizeof(float));

	n=Npoints;
	for(i=0;i<=Npoints;i++)
	{
		x[i]=0.0; w[i]=0.0;
	}
/* Call the routine to generate the abscissa and weights. We pass 
the lower and upper limit and the number of points required, to this program.
the routine returns the abscissa and weights in the pointer arrays  */	
	gauleg(lower_lmt,upper_lmt,x,w,Npoints);

/* here is a way to generate the data file name. the name of the file here will be 
"gauslegNpoints.dat" with "Npoints" replaced by its numerical value */
        sprintf(fname,"gausleg%d.dat",Npoints);

	fp1=fopen(fname,"w");
	for(i=1;i<=Npoints;i++)
	{
		fprintf(fp1,"%f %f\n",x[i],w[i]);
	}
      fclose(fp1);
/* compute  the integral as the sum of the function values multiplied by the 
weights */
	S=0.0;
	for(i=1;i<=Npoints;i++)
	{  S=S+w[i]*pow(x[i],2)*exp(-2.0*x[i]);}
	
		printf("%d %f\n",Npoints,S);
}

/* the function to genearate the abscissa and weights using 
Gauss-Legandere  qudrature rules */
void gauleg(float x1, float x2, float x[], float w[], int n)
{
	int m,j,i;
	double z1,z,xm,xl,pp,p3,p2,p1;

	m=(n+1)/2;
	xm=0.5*(x2+x1);
	xl=0.5*(x2-x1);
/* find m zeros of the Legandere polynomial in the interval -1 to +1 */
	for (i=1;i<=m;i++) {
		z=cos(3.141592654*(i-0.25)/(n+0.5));
		do {
			p1=1.0;
			p2=0.0;
			for (j=1;j<=n;j++) {
				p3=p2;
				p2=p1;
				p1=((2.0*j-1.0)*z*p2-(j-1.0)*p3)/j;
			}
			pp=n*(z*p1-p2)/(z*z-1.0);
			z1=z;
			z=z1-p1/pp;
		} while (fabs(z-z1) > EPS);
/* rescale the values to the limits required */
		x[i]=xm-xl*z;
		x[n+1-i]=xm+xl*z;
/* calculate the weight */
		w[i]=2.0*xl/((1.0-z*z)*pp*pp);
		w[n+1-i]=w[i];
	}
}
#undef EPS

