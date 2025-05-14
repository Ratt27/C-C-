# include<stdio.h> 
void main()
{
	int a[15],max=0,secmax=0,i;
	printf("\n enter the numbers");
	for(i=0;i<15;i++)
	{
		scanf("%d",&a[i]);
		if (a[i]>max)
		{
			secmax =max;
			max=a[i];
		}
		else if(a[i]>secmax&&a[i]!=max)
		{
			secmax=a[i];	
		}
		
		
	}
	printf("\n max=%d,secondmax =%d\n",max, secmax);
}