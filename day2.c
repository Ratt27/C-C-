 #include<stdio.h>
 void main()
 {

   int v,num,p,j,k,l;
	printf(" enter a number:\n");
	scanf("%d",&num);
	p=num/100;
	v=num%100;
	j=v/10;
	k=v%10;
	l=k*100+j*10+p;
	if(l==num)
	{
		printf("it is a palindrome number %d");
	}
	else
	{
printf(" it is not a palindrome number %d");
	}
	int o;
	o=pow(p,3)+pow(j,3)+pow(k,3);
	if(o==nom)
	{
		printf("it is an armstring number %d");
		
	}
	else
	{
	printf("it is not a palindrome number %d");
		
	}
 }
	
   

   