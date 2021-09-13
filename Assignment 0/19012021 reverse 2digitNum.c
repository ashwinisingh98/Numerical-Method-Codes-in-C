//Program to reverse a two digit number

#include<stdio.h>

int main(void)
{
	int num,revn=0;
	printf("Enter a 2 digit number: ");
	scanf("%d",&num);
	while(num!=0)
	{
		revn=(revn*10)+num%10;
		num=num/10;	
	}
	printf("The number with digit reversed is: %d",revn);
	return 0;
}
