o# include<stdio.h>
void main()
{
	int a,i,c=1;
	printf("enetr a number ");
	scanf("%d",&a);
	i=a;
	while(i>=1)
	{
		c=c*i;
		i--;
	}
	printf("the value is %d\n",c);
}