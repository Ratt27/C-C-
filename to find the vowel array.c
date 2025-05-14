#include<stdio.h> 
void  main()
{
	int i,n,c=0;
	char result;
	printf("enter the range\n");
	char a[20];
	printf("enter  the character\t");
	gets(a);
	for (i=0;a[i]!='\0';i++)
		
		{
			if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
			{
				result=a[i];
				printf("the vowels are %c\n",result);
				c++;
			
			}
				
		}
			printf("the no of vowels : %d\n",c);
				
}