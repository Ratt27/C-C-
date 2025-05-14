#include<stdio.h>
void main()
{
	int num,a;
	printf("enter anumber");
	scanf("%d",&num);
	a=num%2;
	switch(a)
	{
		case 0:printf("the number is even");
		break;//here we are using 0 due to actual value
	default: printf("the number is odd");
	break;
	}
}