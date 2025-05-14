#include<stdio.h> 
void main()
{
	int a[3][3],i,j,s1=0, s2=0;
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			printf("enter the numbers for matrix\n");
			scanf("%d",&a[i][j]);
		}
	}
		for (i=0;i<3;i++)
     	{
		for (j=0;j<3;j++)
		{
			if(i==j)
			{
				s1+=a[i][j];	
			}
			if ((i+j)==2)
			{
				s2+=a[i][j];
			}
			
			
		}
       }
        printf("the sum of the major daigonal is  %d\n",s1);
        printf("the sum of the minor daigonal is %d\n",s2);
}