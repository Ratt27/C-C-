#include<stdio.h> 
void main()
{
	int i,j;
	for (i=5;i>=1;i--)
	{
		for(j=1;j<=i;j++)
		{
			printf("%d",j);
		}
		printf("\n");
	}
	int m,n,rows,k;
	printf("enter the no of rows");
	scanf("%d",&rows);
	for(m=1;m<=rows;m++)
	{
		k=1;
		for(n=1;n<=rows;n++)
		{
			if(n<=rows+1-m)
			{
				printf("%d",k);
			k++;	
			}
			else
			{
				printf(" ");
			}
			
		}
		printf("\n");
	}
}