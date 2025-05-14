#include<stdio.h> 
void main()
{
	int i,j,l;
	char s1[30],cnt,c;
	printf("enter the string\t");
	gets(s1);
		for(i=0;s1[i]!='\0';i++)
	{
		cnt++;
	
	}	
	printf("the length of the string %d\n",cnt);
	
	
	for(j=0;j<cnt/2;j++)
	{
		c=s1[j];
		s1[j]=s1[cnt-1-j];
		s1[cnt-1-j]=c;
	
		
		
	}
		printf(" string in the reverse order is %s\t",s1);
	
}