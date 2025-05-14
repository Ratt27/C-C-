#include<stdio.h> 
void main()
{
char str[20][30],s[10];
int round,r,i;
printf("enter 5 names\t");
for(i=0;i<=4;i++)
	gets(str[i]);
for(round=1;round<=4;round++)
{
	for(i=0;i<=4-round;i++)
	{
		r=strcmp(str[i],str[i+1]);
	

if(r>0)
{
	strcpy(s,str[i]);
	strcpy(str[i],str[i+1]);
	strcpy(str[i+1],s);
}
	}
}
printf("strings in dictionary order \n");
for(i=0;i<=4;i++)
	puts(str[i]);	
}

