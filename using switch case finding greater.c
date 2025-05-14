#include<stdio.h>
void main()
{
	int a,b,k;
	printf(" enter a number");
	scanf("%d",&a);
	printf("enter anumber");
	scanf("%d",&b);
	k=a>b;
	switch(k)
	{
	case 1: printf("A is greater");
	break;
    default: printf	("B is greater");
    break;
	}
}