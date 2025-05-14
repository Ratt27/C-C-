#include<stdio.h> 
void main()
{
	int a[]={2,3,4,5,6,8};
	int *p=a;
	int *q=&a[3];
	printf("q-p %d\n",q-p);
	printf("p-q %d\n",p-q);
	
}