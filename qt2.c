#include<stdio.h> 
#include<math.h>
int main()
{
int n,i,sum=0;
printf("enter the no of terms\t");
scanf("%d",&n);
for	(i=1;i<=n;i++)
{
if(i%2==0)
	{
	sum=sum-(pow(i,2));	
	}
	else
	{
		sum=sum+(i*i);
	}
		
}
printf("the sum is %d",sum);

	
}