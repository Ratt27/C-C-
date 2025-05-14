#include<stdio.h>
void main()
{
int a,b,c;
	printf(" enter anumber");
	scanf("%d",&a);
		printf(" enter anumber");
	scanf("%d",&b);
		printf(" enter anumber");
	scanf("%d",&c);
	if(a>b)
	{
		if(a>c)
		{
			printf("greater is A");	
		}
		else
		{
		printf("gfeater is C");	
		}
	}
	 else if(b>a)
	 {
	 	if(b>c)
		 {
		 	printf("greater is B");
		 }
		 else
		 {
			 printf(" greater is C ");
		 }
		 }
		 else
		 {
			 printf("all the numbers are equal");
		 }
	
	 
		
}
