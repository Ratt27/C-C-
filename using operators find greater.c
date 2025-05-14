#include<stdio.h>
void main()
{
	int a, b,c;
	printf("enter a number");
	scanf("%d",&a);
		printf("enter a number");
	scanf("%d",&b);
		printf("enter a number");
	scanf("%d",&c);
	if(a>b&&a>c)
	{
		printf("thr greater is A");
	}
	else if(b>a&&b>c)
	{
		printf("the greater is B ");	
	}
	else if(c>a&&c>b)
	{
		printf("the greater is C");
	}

	else
	{
		printf("all numbers are equal!!! ");
	}
}