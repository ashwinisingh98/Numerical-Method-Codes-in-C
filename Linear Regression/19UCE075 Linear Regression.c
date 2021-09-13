//Implementation of least square linear regression method
//Coded by Ashwini Kumar Singh on 15-Feb-2021

#include<stdio.h>

int main(void) {
    printf("\n************************************************************************************\n");
    printf("\nImplementation of least square linear regression method\n");
    printf("\nCoded by Ashwini Kumar Singh on 15-Feb-2021\n");
    printf("\n************************************************************************************\n");

    FILE *input=fopen("coordinatesLinRegr.txt","r");
	FILE *output=fopen("solutionLinRegr.txt","w");

    int i,j,n;

    fscanf(input,"%d",&n);

    float x[n],y[n],s1=0,s2=0,s3=0,s4=0,a,d,b;

    for(i=0;i<n;i++) {
        fscanf(input,"%f",&x[i]);
        fscanf(input,"%f",&y[i]);
    }
    printf("\nThe values of x and y are :\n");
    for(i=0;i<n;i++) {
        printf("%f\t%f\n",x[i],y[i]);
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
    printf("\nThe values of a and b are : %f\t%f\n",a,b);
    fprintf(output,"\nThe values of a and b are : %f\t%f\n",a,b);
    printf("\nThe Required Linear Relation is : \n");
    fprintf(output,"\nThe Required Linear Relation is : \n");
    if(b>0){
        printf("\ny=%f+%fx\n",a,b);
        fprintf(output,"\ny=%f+%fx\n",a,b);
    }
    else {
        printf("y = %f %fx",a,b);
        fprintf(output,"y = %f %fx",a,b);
    }

    fclose(input);
    fclose(output);

    printf("\n************************************************************************************\n");
    printf("\nImplementation of least square linear regression method\n");
    printf("\nCoded by Ashwini Kumar Singh on 15-Feb-2021\n");
    printf("\n************************************************************************************\n");

    return 0;
}
