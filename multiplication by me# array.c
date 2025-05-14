#include <stdio.h> 
void main()
{
int i,j,r1,c,c2;
printf("enter the row no for 1st matrix\n");
scanf("%d",&r1);
printf("enter the coloumn no of the 1st matrix which is the row no of 2nd matrix\n");
scanf("%d",&c);
printf("enter the coloumn no of the 2nd matrix\n");
scanf("%d",&c2);
int a[10][10],b[10][10];

for (i=0;i<r1;i++)
{
	for(j=0;j<c;j++)
	{
printf("enter the elemnts for matrix A\t");
scanf("%d",&a[i][j]);
	}
}
for (i=0;i<c;i++)
{
	for(j=0;j<c2;j++)
	{
		printf("enter the elemnts for matrix B\t");
		scanf("%d",&b[i][j]);
	}
}
int k,m,n,v[r1][c2];
for (m=0;m <r1;m++)
{
	for(n=0;n<c2;n++)
	{
	int	sum=0;
	for (k=0;k<c;k++)
	{
		sum+=a[m][k]*b[k][n];
		v[r1][c2]=sum;
		
		
		
	}
		printf("%d",v[r1][c2]);
		

	
	
	
	}
	printf("\n");
}
}
	

