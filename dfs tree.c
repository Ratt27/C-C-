#include<stdio.h> 
#include<conio.h> 
int a[20][20],reach[20],n;
void dfs( int v)
{
	int i;
	reach[v]=1;
	for(i=1;i<=n;i++)
		if(a[v][i]&&!reach[i])
		{
			printf("\n%d->%d",v,i);
			dfs(i);
		}
}
int main(int argc, char**argv)
{
	int i,j, count=0;
	printf("\n enter number of vertices:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		reach[i]=0;
		for(j=1;j<=n;j++)
			a[i][j]=0;
	}
	printf("\n enter the adjacency  matrix:\n");
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
		dfs(1);
		printf("\n");
		for(i=1;i<=n;i++)
		{
			if (reach[i]==1)
				count++;
		}
		if(count==n)
		{
			printf("\n Graph is  connected ");
		}
		else
		{
			printf("\n graph is not connected");
		}
		return 0;
}