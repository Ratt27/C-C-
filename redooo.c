#include<stdio.h> 
void main()
{
	int n,ran;
printf("enter the number you want to check\t");
scanf ("%d",&n);
printf("enter the  range of numbers");
scanf("%d",&ran);
int a[ran][ran],i, j;

	for (i=0;i<ran;i++)
	{
		for (j=0;j<ran;j++)
		{
         printf("enter the numbers");
         scanf("%d",&a[i][j]);
		}
	}


int f=0;

	for (i=0;i<ran;i++)
	{
		for (j=0;j<ran;j++)
		{
			if (a[i][j]==n)
				f++;
		}
	}
	 if (f>=1)
	 {
	 	printf("yes the number is present\n");
	 	printf("the no of times the no is present : %d\t",f);
	 }
	 else 
	 {
	 	printf(" the  number is not present");
	 }
}
			