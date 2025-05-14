// replace and find and replace numbers
#include<stdio.h> 
void main()
{
	int a[10],n1,n2,i;
	printf("\n enter 10 numbers");
	for(i=0;i<10;i++)
	{
	scanf("%d",&a[i]);	
	}
		
	printf("enter the number you want to replace");
	scanf("%d",&n1);
	printf("enter the number  which you wnat to replace");
	scanf("%d",&n2);
	for(i=0;i<10;i++)
	{
		if(a[i]==n1)
		{
			a[i]=n2;
		}
		
		
		
	}
	for(i=0;i<10;i++)
			printf("\n%d",a[i]);
		printf("\n updated array\n");
	
	
}