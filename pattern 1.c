#include<stdio.h>
void main()

{
	int i,j;
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("*");
			
		}
		printf("\n");
	}
	
	
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
			
		}
		printf("\n");
}

	
	for(i=1;i<=3;i++)
	{
		for(j=i;j>=1;j--)
		{
			printf("%d",j);
			
		}
		printf("\n");
}

	for(i=1;i<=8;i++)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j+1);
			
		}
		printf("\n");
	}


	for(i=2;i<=8;i++)
	{
		for(j=0;j<i;j++)
		{

			printf("%d",j++);
			
		}
		printf("\n");
	}
}

