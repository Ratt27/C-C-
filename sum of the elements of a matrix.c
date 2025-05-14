#include<stdio.h> 
void main()
{
	int a[3][3],i,j,sum=0;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("enter the numbers for matrix\n");
			scanf("%d",&a[i][j]);
		}
	}
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			sum+=a[i][j];
		}
	}
	printf("the sum of the elements of the matrix is %d\n",sum);
}