#include<stdio.h>
void main()
{
	int prv=0, pre=1,trm,i,n;
	printf("input no of terms to  display:");
	scanf("%\d",&n);
	printf("here is the fibonacci series %\d",prv);
	printf(" %\d",pre);
	for(i=3;i<=n;i++)
	{
		trm=prv+pre;
		printf("%\d",trm);
		prv=pre;
		pre=trm;
	}
}