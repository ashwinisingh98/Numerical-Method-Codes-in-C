//Implementation of Gauss-Jacobi Method
#include<stdio.h>
#include<conio.h>
#include<math.h>

/* Arrange systems of linear
   equations to be solved in
   diagonally dominant form
   and form equation for each
   unknown and define here
*/
/* In this example we are solving
   x-2y+5z=12
   5x+2y-z=6
   2x+6y-3z=5
*/
/* Arranging given system of linear
   equations in diagonally dominant
   form:
   5x+2y-z=6
   2x+6y-3z=5
   x-2y+5z=12
*/
/* Equations:
   x = (6-2y+z)/5
   y = (5-2x+3z)/6
   z = (12-x+2y)/5
*/
/* Defining function */
#define f1(x,y,z)  (6-2*y+z)/5
#define f2(x,y,z)  (5-2*x+3*z)/6
#define f3(x,y,z)  (12-x+2*y)/5

/* Main function */
int main()
{
 float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
 int count=1;

 printf("\n************************************************************************************\n");
 printf("\nImplementation of Gauss-Jacobi method\n");
 printf("\nCoded by Ashwini Kumar Singh on 09-Feb-2021\n");
 printf("\n************************************************************************************\n");

 printf("Enter tolerable error:\n");
 scanf("%f", &e);
 //printf("\nEnter initial guesses of x y z:\n");
 //scanf("%f %f %f", &x0,&y0,&z0);

 printf("\nCount\tx\ty\tz\n");
 do
 {
  /* Calculation */
  x1 = f1(x0,y0,z0);
  y1 = f2(x0,y0,z0);
  z1 = f3(x0,y0,z0);
  printf("%d\t%0.4f\t%0.4f\t%0.4f\n",count, x1,y1,z1);

  /* Error */
  e1 = fabs(x0-x1);
  e2 = fabs(y0-y1);
  e3 = fabs(z0-z1);

  count++;

  /* Set value for next iteration */
  x0 = x1;
  y0 = y1;
  z0 = z1;
 }while(e1>e && e2>e && e3>e);

 printf("\nSolution: x=%0.3f, y=%0.3f and z = %0.3f\n",x1,y1,z1);

// getch();
 return 0;
}
