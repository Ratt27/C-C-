#include<stdio.h> 
void main()
{
	char s1[20];
	int i;
	printf("enter the string\t");
	gets(s1);
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]>='a'&&s1[i]<='z')
		{
			s1[i]=s1[i]-32;
		}
	}
	printf("the string in the uppercase will  be %s\n",s1);
	
	
	
}