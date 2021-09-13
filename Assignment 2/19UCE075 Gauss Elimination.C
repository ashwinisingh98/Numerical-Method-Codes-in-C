/*Implementation of solution of system of linear equations by Gauss Elimination method.
 Coded by Ashwini Kumar Singh on 10-Feb-2021*/

#include<stdio.h>
#include<math.h>

int main(void) {
    int i,j,k,n;
    printf("\n************************************************************************************\n");
    printf("\nImplementation of solution of system of linear equations by Gauss Elimination method\n");
    printf("\nCoded by Ashwini Kumar Singh on 10-Feb-2021\n");
    printf("\n************************************************************************************\n");
    printf("\nEnter the value of n \n");
    scanf("%d",&n);

    float x[n],a[n][n],c[n];

    printf("\nEnter the right hand side constants\n");
    for(i=0;i<n;i++) {
        scanf("%f",&c[i]);
    }

    printf("\nEnter the coefficients row wise\n");
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            scanf("%f",&a[i][j]);
        }
    }

    for(k=0;k<n-1;k++) {
        for(i=k+1;i<n;i++) {
            for(j=k+1;j<n;j++) {
                a[i][j]=a[i][j]-(a[i][k]/a[k][k])*a[k][j];
            }
            c[i]=c[i]-(a[i][k]/a[k][k])*c[k];
        }
    }
    x[n-1]=c[n-1]/a[n-1][n-1];

    printf("\nThe Solution is : \n");
    printf("x[%d]=%f\n",n-1,x[n-1]);
    for(k=0;k<n-1;k++) {
        i=n-k-2;
        for(j=i+1;j<n;j++) {
            c[i]=c[i]-(a[i][j]*x[j]);
        }
        x[i]=c[i]/a[i][i];
        printf("x[%d]=%f\n",i,x[i]);
    }
    return 0;
}
