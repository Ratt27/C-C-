#include<stdio.h> 
void main()
{
	char a[20],b[20];
	printf("enter your name\t");
	gets(a);
	printf("your name after rev %s\n",strrev(a));
}