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
	int b[i][j];
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			b[i][j]=a[j][i];
				printf(" %d",b[i][j]);
		}
		printf("\n");
	}

}
	