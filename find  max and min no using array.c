# include<stdio.h> 
void main()
{
	 int a[10],i,max=0,min=5678;
	 printf("enter 10 numbers");
	 for(i=0;i<10;i++)
	 {
	 	scanf("%d",&a[i]);
	 	if (a[i]>max)
		 {
		 max=a[i];	
		 }
	 		
	 	else if(a[i]<min)
		 {
		 	min=a[i];
		 }
	 
	 }
	 	printf("\n the maximum is %d\t and the minmum is %d\n",max, min);
		 	
}