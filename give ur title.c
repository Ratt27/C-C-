#include<stdio.h> 
void main()
{
	char a[20];
	int i,p;
	printf("enter a string \t");
	gets(a);
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==' ')
		{
			p=i;
			break;
		}
	}
	for(i=p+1;a[i]!='\0';i++)
	{
		printf("%c",a[i]);
	}
}