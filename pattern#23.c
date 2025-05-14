#include <stdio.h> 
void main()
{
	int i,j,k=0,rows,n;
	printf("enter no  of rows");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		n=(rows+1)/2;
		i<=n?k++:k--;
		for(j=1;j<=rows;j++)
		{
			if(j>=(n+1)-k&&j<=(n-1)+k)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			
		}
		printf("\n");
	}
}