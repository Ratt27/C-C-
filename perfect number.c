#include<stdio.h>
void main()
{
	int a,b,c,d,f,g,h;
	printf("enter a number");
	scanf("%d",&a);
	b=a/100;
	c=a%100;
	d=c/10;
	f=c%10;
	g=f*b*d;
	h=f+b+d;
	if(g==h)
	{
	printf("it is a perfect number");
		
	}
	else
	{
		printf(" it is not a perfect number");
	}	
	
}