#include<stdio.h> 
struct std
{
	int rat,sub;
	int sum ,marks[20],id;
} ;
int main()
{
	struct std rat,sub, sum, marks[20],id;
	int i;
	printf("enter the id for rattriz");
	scanf("%d",&rat.id);
	printf("enter the marks for Rattriz");
	for (i=0;i<5;i++)
	{
		scanf("%d",&rat.marks[i]);
	}
	for(i=0;i<5;i++)
	{
		rat.sum=rat.sum+rat.marks[i];
		
	}
	printf("the totals marks obtained%d\n",rat.sum);
		
		
		
		printf("enter the id for subesha");
	scanf("%d",&sub.id);
	printf("enter the marks for subesha");
	for (i=0;i<5;i++)
	{
		scanf(" %d",&sub.marks[i]);
	}
	for(i=0;i<5;i++)
	{
		sub.sum=sub.sum+sub.marks[i];
		
	}
	printf("the totals marks obtained%d\n",sub.sum);
	
	
	
	printf("u hav enetered details of two student");
	printf("\n rattriz details:");
	printf(" id %d\n",rat.id);

    printf(" total sum %d\n",rat.sum);	
	
		printf("\n  subesha details:");
	printf(" id %d\n",sub.id);

    printf(" total sum %d\n",sub.sum);	
	
	
	}