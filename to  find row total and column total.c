#include<stdio.h> 
void main()
{
	int a[3][3],i,j;
	printf("enter the numbers\n");
		for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&(a[i][j]));	
		}
	}
	

	int sum=0,SUM=0;

	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			sum+=a[i][j];
		}
		printf(" row total %d\n",sum);	
	}

		sum=0; 
	for(j=0;j<3;j++)
	{
		for(i=0;i<3;i++)
		{
			SUM+=a[i][j];
		}
		printf(" coloumn total %d\n",SUM);
	}
	
		SUM=0;
}