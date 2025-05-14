#include<stdio.h> 
void main()
{
	int a,b,i,min;
	printf("enter 2 number");
	scanf("%d%d",&a,&b);
	min=a<b?a:b;
	for(i=2;i<=min;i++)
	{
		if(a%i==0&&b%i==0)
		{
			break;
		}
	}
		if(i==min+1)
		{
			printf("they are co-prime",&a,&b);
		}
		else
		{
			printf(" they are non co prime");
		}
	
}