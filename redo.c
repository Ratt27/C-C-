#include <stdio.h> 
void main()
{
int n,i,j;
printf("enter the range");
scanf("%d",&n);
int a[n][n],b[n][n];
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		
		{
			printf("enter the numbers for matrix A\t");
			scanf("%d",&a[i][j]);
		}
}
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
		
		{
			printf("enter the numbers for matrix B\t");
			scanf("%d",&b[i][j]);
		}
}
int c[i][j];
int sum=0;
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		sum+=a[i][j]+b[i][j];
		c[i][j]=sum;
		printf(" %d",c[i][j]);
		sum=0;
		
	}
	printf("\n");

}


}

