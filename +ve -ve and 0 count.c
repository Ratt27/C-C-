#include<stdio.h> 
void main()
{
	int a[10],i,c1=0,c2=0,c3=0;
	printf("enter  10 numbers");
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	for (i=0;i<10;i++)
	{
		if(a[i]>0)
			c1++;
		else if(a[i]<0)
			c2++;
		else 
			c3++;
	}
	printf("  total  positive numbers %d\n",c1++);
	printf(" total negetive numbers %d \n",c2++);
	printf(" total noof  zeroes %d \n",c3++);
}
