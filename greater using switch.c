#include<stdio.h> 
void main()
{
	int a,b,c;
	char m;
	printf("enter a number");
	scanf("%d",&a);
		printf("enter a number");
	scanf("%d",&b);
		printf("enter a number");
	scanf("%d",&c);
	m=(a>c&&a>b)?0:(b>a&&b>c)?1:2;
	switch(m)
	{
		case 0:printf("a is greater");
		break;
	 case 1:printf(" B is greater");
	 break;
 default:printf("C is greatest");
 break;
	}
	
}