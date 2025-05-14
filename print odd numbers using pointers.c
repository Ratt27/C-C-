#include<stdio.h> 
void main()
{
	int i,a[5],*p;
	p=&a[0];
	printf("enter 5 numbers\n");
	for(i=0;i<=4;i=i++)
	{
		
		scanf("%d",p+i);	
	}
	
	for(i=0;i<=4;i=i+2)
	{
		printf("%d",*(p+i));
	}
}
