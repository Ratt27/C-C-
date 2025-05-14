#include<stdio.h> 
void main()
{
	char a[20],b[20];
	printf("enter a string: ");
	gets(a);
	printf("enter another string: ");
	gets(b);
	if(strcmp(a,b)==0)
	{
		printf("both the strings are equal");
	}
	else
	{
		printf("both the strings are not equal");
	}
}