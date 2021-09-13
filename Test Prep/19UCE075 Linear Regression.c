//Implementation of least square linear regression method
//Coded by Ashwini Kumar Singh on 15-Feb-2021

#include<stdio.h>

int main(void) {
    printf("\nImplementation of least square linear regression method\n");
    printf("\nCoded by Ashwini Kumar Singh on 15-Feb-2021\n");
    printf("\n************************************************************************************\n");

    FILE *input=fopen("coordinatesLinRegr1.txt","r");
	FILE *output=fopen("solutionLinRegr.txt","w");

    int i,j,n;

    fscanf(input,"%d",&n);

    float x[n],y[n],s1=0,s2=0,s3=0,s4=0,a,d,b;

    for(i=0;i<n;i++) {
        fscanf(input,"%f",&x[i]);
        fscanf(input,"%f",&y[i]);
    }
    printf("\nThe %d values of x and y read from 'coordinatesLinRegr.txt' and calculated x*y and x*x are :\nx\t\ty\t\tx*y\t\tx*x\n\n",n);
    for(i=0;i<n;i++) {
        printf("%f\t%f\t%f\t%f\n",x[i],y[i],x[i]*y[i],x[i]*x[i]);
    }
    for(i=0;i<n;i++) {
        s1=s1+x[i];
        s2=s2+x[i]*x[i];
        s3=s3+y[i];
        s4=s4+x[i]*y[i];
    }
    //solution of linear equation in two variable using cross multiplication method
    d=n*s2-s1*s1;
    a=(s2*s3-s1*s4)/d;
    b=(n*s4-s1*s3)/d;
    printf("\nThe Summation values are :\nS[xi]\t\tS[yi]\t\tS[xi*yi]\tS[xi*xi]\t\t\n\n%f\t%f\t%f\t%f\n\n",s1,s3,s4,s2);
    printf("\nThe Required Linear Eqns are : \n");
    printf("\n(%d)a + (%f)b = (%f)\n",n,s1,s3);
    printf("\n(%f)a + (%f)b = (%f)\n\n",s1,s2,s4);
    printf("\nThe values of a and b are : %f\t%f\n",a,b);
    fprintf(output,"\nThe values of a and b are : %f\t%f\n",a,b);

    fprintf(output,"\nThe Required Linear Relation is : \n");

    printf("y = (%f)+(%f)x\n",a,b);
    fprintf(output,"\ny = (%f)+(%f)x\n",a,b);

    float xn=0.0;
    printf("\nEnter the value of 'x' for which y is required: ");
    scanf("%f",&xn);
    printf("\n\ny = (%f)+(%f)*(%f)\n",a,b,xn);
    printf("\n\ny = (%f)\n",(a+b*xn));



    fclose(input);
    fclose(output);

    printf("\n************************************************************************************\n");
    printf("\nImplementation of least square linear regression method\n");
    printf("\nCoded by Ashwini Kumar Singh on 15-Feb-2021\n");
    return 0;
}
