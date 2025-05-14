#include<stdio.h> 
void main()
{
	int r,c;
	printf("enter the no of coloumns");
	scanf("%d",&c);
	printf("enter the no of rows");
	scanf("%d",&r);
	int a[r][c],i,j;
	printf("enter the numbers\n");
		for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&(a[i][j]));	
		}
	}
	

	int sum=0,SUM=0;

	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sum+=a[i][j];
		}
	
	}
		printf(" row total %d\n",sum);	

		sum=0; 
	for(j=0;j<c;j++)
	{
		for(i=0;i<r;i++)
		{
			SUM+=a[i][j];
		}
	
	}
		printf(" coloumn total %d\n",SUM);
	
		SUM=0;
}