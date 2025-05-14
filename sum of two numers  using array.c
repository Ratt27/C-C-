#include<stdio.h> 
void main()
{
	int a[10],i,s=0;
	printf("\n enter 10 numbers");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
		
	}
	for (i=0;i<10;i++)
	{
		s=s+a[i];
	}
	printf("\n sum is %d\n", s);
}