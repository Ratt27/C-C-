#include<stdio.h>
int getdigits(int n)
{
	int c=0;
	while(n>0)
	{
		c++;
		n=n/10;
	}
	return c;
}
int getplaceddigit(int n,int v)
{
	int r,c=0;
	while(n>0)
	{
		c++;
		r=n%10;
		n=n/10;
		if(c==v)
		{
			return r;
		}
	}
	return 0;
}
void enque(int mat[10][10],int k,int n)
{
	int i,j;
	for(i=0;mat[k][i]!=0;i++);
		mat[k][i]=n;
}
void dequeue(int mat[10][10], int arr[])
{
	int i,j,k=0;
	for(i=0;i<10;i++)
    for(j=0;mat[i][j]!=0;j++)
	{
		arr[k++]=mat[i][j];
	}
}
void zero(int mat[10][10])
{
	int i,j;
	for( i=0;i<10;i++)
		for(j=0;j<10;j++)
			mat[i][j]=0;
}
int main()
{
	int arr[10],i,j,k,max,c;
	int mat[10][10];
	max=0;
	for(i=0;i<10;i++)
	{
		printf("enter the elements");
		scanf("%d",&arr[i]);
		c=getdigits(arr[i]);
		if(c>max)
			max=c;
	}
	for(c=1;c<=max;c++)
	{
		zero(mat);
		for(i=0;i<10;i++)
		{
			k=getplaceddigit(arr[i],c);
			enque(mat,k,arr[i]);
		}
		dequeue(mat,arr);
	}
	for(i=0;i<10;i++)
		printf("%d ,",arr[i]);
}