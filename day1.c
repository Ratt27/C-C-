# include<stdio.h>
void main()
{
	int a,b,c;
	a=10;
	b=20;
	c=a+b;
	printf(" the result is %d\n",c);
	
	int m,n,tt,o,q,t;
	printf(" enter a number %d\n");
	scanf("%d",& m);
	n=m/100;
	o=m%100;
	tt=o/10;
	q=o%10;
	t=q*100+tt*10+n;
	printf("the reverse number is : %d\n",t);

	int z;
	printf(" enter a number %d\n");
	scanf("%d",&z);
printf("%d",z%2==0);
printf("number is divisble by 2");
int age;
printf("enter age:");
scanf("%d",&age);
if(age>18)
{
	printf("adult ,");
	printf("they can vote ,");
	printf("they can drive\n");
	
	
	
}	
else{ printf(" not adult, cannot vote , cannot drive \n");}
	int day;
printf("enter a day between 1 to 7 :");
scanf("%d",&day);
switch(day)
{
	case 1: printf("monday\n");
	break;
    case 2: printf("tuesday");
    break;
    case 3: printf("wednesday");
    break;
    case 4: printf("thursday");
    break;
    case 5: printf("friday");
    break;
    case 6: printf("saturday");
    break;
    case 7: printf("sunday");
    break;
    default:printf(" not a valid day");

}

	  int num,p,j,k,l;
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
}
	
	
	



  