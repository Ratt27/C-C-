# include<stdio.h>
void main()
{
	int i,n;
	int g=0;
	printf("enetr a number");
	scanf("%d",&n);
	i=0;
	while (n!=0)
	{
		n=n/10;
		i++;
	}
	printf("number of digits %d\n",i);
}