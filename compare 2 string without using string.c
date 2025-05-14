#include<stdio.h> 
void main()
{
	int flag=0,i;
	char s1[30],s2[30];
	printf("ENTER THE 1ST WORD\t");
	gets(s1);
	printf("ENTER THE 2ND WORD\t");
	gets(s2);
	for(i=0;s1[i]!='\0'||s2[i]!='\0';i++)
	{
		if(s1[i]!=s2)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("those  two are not same");
	}
	if(flag==0)
	{
		printf("they are same");
	}
	
}