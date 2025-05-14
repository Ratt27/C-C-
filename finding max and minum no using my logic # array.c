#include<stdio.h> 
void main()
{
	int a[5],i,max,min;
	printf("enter the numbers");
	for(i=0;i<5;i++)
	{
		scanf("%d",&a[i]);
	}
	max=a[0];
	min=a[4];
	for(i=0;i<5;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
		else if(a[i]<min)
		{
			min=a[i];
		}
	
	}
		printf("the maximum no is%d\n",max);
		printf("the minimum no is %d\n",min);
}