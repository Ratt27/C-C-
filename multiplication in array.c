#include<stdio.h> 
void main()
{
	int a[10][10],b[10][10],mul[10][10],r,c,i,j,k;
	
	printf("enter the no of rows=\n");
	scanf("%d",&r);
	printf("enter the no of coloumn=\n");
	scanf("%d",&c);
	printf("enter the  elemnts of 1st matrix\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	printf("enter the elements for 2nd matrix\n");
	for (i=0;i<r;i++)
	{
		for (j=0;j<c;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
	printf("multiply of matrix=\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			mul[i][j]=0;
			for (k=0;k<c;k++)
			{
				mul[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for (i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",mul[i][j]);
		}
		printf("\n");
	}
}