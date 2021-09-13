//Program for arranging squares of numbers in ascending order

#include<stdio.h>

int main(void)
{
    int n,i,j,temp;
    printf("\nEnter no. of data inputs: ");
    scanf("%d",&n);
    int a[n];

    printf("\nEnter %d integers:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&temp);
        a[i]=temp*temp;
    }


    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                }
            }
    printf("\nSquare of %d integers arranged in ascending order is :\n",n);
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);

	return 0;
}
