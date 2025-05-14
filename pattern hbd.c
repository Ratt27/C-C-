#include<stdio.h> 
void main()
{
	int i,j,k,rows;
	printf("enter the no of rows");
	scanf("%d",&rows);
	for(i=1;i<=rows;i++)
	{
		k=i;
		for(j=1;j<=2*rows-1;j++)
		{
			if(j>=(rows+1-i)&&j<=(rows-1+i))
			{
				printf("%d",k);
				j<rows?k++:k--;
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}