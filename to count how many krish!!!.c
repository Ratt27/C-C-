#include<stdio.h>
void main()
{
	int num,n,h,sum,fact,i,j,d;
	printf("enter a number");
	scanf("%d",&n);
	for(j=1;j<=n;j++)
	{
		num=j;
		h=num;
		sum=0;
		while(num!=0)
		{
			d=num%10;
			
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
			printf("it  is a krishnamurthy number %d\n",sum);
		}
	}
}