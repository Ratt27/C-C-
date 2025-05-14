#include<stdio.h> 
int main()

{
	int x,z,i;
	printf("enter the value of x\n");
	scanf("%d",&x);
	multiplication(x);
	return 0;
}
void multiplication(int a)
{
	int i, ptd=0;
	for(i=1;i<=12;i++)
	{
		ptd=a*i;
		printf("%d * %d =%d\n",a,i,ptd);
	}
}