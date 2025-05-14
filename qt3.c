#include<stdio.h> 
int main()
{
	int n,i;
	float sum=0;
	printf("enter the limit");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		sum=sum+(float)i/((i-1)*(i+1));
	printf("the  sum  is %f",sum);
	 return 0;
}