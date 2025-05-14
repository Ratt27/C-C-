#include<stdio.h> 
void main()
{
	int i,j,k, rows;
	printf("enter the no of rows");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		k=rows-i;
		for(j=1;j<=rows;j++)
		{
			if(j<=rows+1-i)
			{
				printf("%d",k);
				k--;
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}