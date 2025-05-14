#include<stdio.h> 
void main()
{
	char a[20]={'r','a','t','t','r','i','z','\0'};
	char b[20];
	char c[20]={' ','a','r','m','y'};
	strcpy(b,a);;
	printf("length of the given string%d\n",strlen(a));
	printf("string copied and value of b %s\n",b);
	printf("string after concatenations %s\n",strcat(a,c));
}