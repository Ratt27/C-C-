#include<stdio.h> 
void main()
{
	int n;
	
	do
	{
		scanf("%d",&n);
		if(n%2==0)
		{
			break;
		}
		else
		{
			printf("the number is %d\n",n);	
		}
	
	
	}while(1);
}