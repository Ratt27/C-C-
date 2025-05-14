#include<stdio.h> 
void main()
{
	int i,space,rows,k=0;
	printf("enter the no of rows");
	scanf ("%d",& rows);
	for (i=1;i<=rows;++i,k=0)
	{
		for(space=1;space<=rows-1;++space)
		{
			printf(" ");
		}
		while (k!=2*i-1)
		{
			printf("*");
			++k;
		}
		printf("\n");
	}
}