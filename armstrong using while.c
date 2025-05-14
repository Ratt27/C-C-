# include<stdio.h>
#include<math.h>
void main()
{
	int a,h,g,d=0;
	printf("enter a number");
	scanf("%d",&a);
	h=a;//for storage so that we can use later
	while (a!=0)
	{
		g=a%10;
		d=d+(pow(g,3));
		a=a/10;
	}
	if(d==h)
	{
		printf("it is an armstrong number");
	}
	else
	{
	printf("it is not an armstrong numbr");
	}
}