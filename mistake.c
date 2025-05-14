#include<stdio.h> 
char*remove_extra_spaces(char*s);
int count_words(char*s);
main()
{
	char str[100];
	int no_of_words;
	printf("enter a string");
	gets(str);
    strcpy(str,remove_extra_spaces(str));
	printf("\n string length :%d",strlen(str));
    no_of_words=count_words(str);
	printf("\n number of word :%d",no_of_words);
	getch();
	
}
int count_words(char*s)

{
	int i=0,count=0;
	while(*(s+i))
	{
		if(*(s+i)==' ')
			count++;
		i++;
	}
	return(count+1);
}
char *remove_extra_spaces(char*s);
{
char *p;
int i=0,j=0;m
p*malloc(strlen(s)+1);
while(*(s+i))
{
	while (*(s+i)==' ')
		i++;
	while(*(s+i)!=' '&&*(s+i)!='\0')
	{
		*(p+j)=*(s+i);
		i++;
		j++;
	}
	if(*(s+i)=='\0'&& *(p+j-1)=*' ')
		*(p+j)=*(s+i);
	j++;
}
return (p)	
}