#include<stdio.h> 
void main()
{
	int n;
printf("enter the number you want to check\t");
scanf ("%d",&n);
int a[2][2],i, j;

	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
         printf("enter the numbers");
         scanf("%d",&a[i][j]);
		}
	}


int f=0,c1=0;

	for (i=0;i<2;i++)
	{
		for (j=0;j<2;j++)
		{
			if (a[i][j]==n)
			{
			f=1;
			c1++;	
			}
				
		
		}
	
	}
		
	 if (f>=1)
	 {
	 		
	 	printf("yes the number is present \n ");
	 	printf("the no of times it is present %d\t",c1);
	 }
	 else 
	 {
	 	printf(" the  number is not present");
	 }
}
			