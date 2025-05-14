#include<stdio.h> 
void main()
{
	int num,c, value=0,h;
	printf("enter a number");
	scanf("%d",&num);
	h=num;
	while(num!=0)
	{
		c=num%10;
		value= (value*10)+c;
		num=num/10;
		
	}
	if (value==h)
	{
		printf("it is a palindrome number");

	}
	else
	{
		printf("it is not a palindrome no");
	}
}