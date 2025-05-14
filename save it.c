#include<stdio.h>
void main()
{
	int num,h,sum=0,d,i,fact;
	printf("enter the number");
	scanf("%d",&num);
	h=num;
	while(num!=0)
	{
		d=num%10;
		i=1;
		fact=1;
		for(i=1;i<=d;i++)
		{
			fact=fact*i;
		}
		sum=sum+fact;
		num=num/10;
	}
	if(h==sum)
	{
		printf("it is a krishnumurthy number");
		
	}

	else
	{
		printf(" it is not");
	}		
}