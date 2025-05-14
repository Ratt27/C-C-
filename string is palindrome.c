#include<stdio.h> 
void main()
{
	int n,i,cnt=0,p=0,flag=0;
	char a[20],b[20];
	printf("enter a string\t");
	gets(a);
	for(i=0;a[i]='\0';i++)
	{
		cnt++;
	}
	for(i=cnt-1;i>=0;i--)
	{
		b[p]=a[i];
		p++;
		
	}

	for(i=0;i<cnt;i++)
	{
		if(a[i]!=b[i])
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("string is palindrome");
	}
	else
	{
		printf("not a palindrome");
	}
	
		
			
}