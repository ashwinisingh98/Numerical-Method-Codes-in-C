//
#include<stdio.h>

int main(void)
{
	int i,n,sum=0;
	printf("Enter the integer: ");
	scanf("%d",&n);
	for(i=0;i<=n;i+=1)
	{
		sum+=i;
	}
	
	printf("the required sum = %d",sum);
	return 0;
}
