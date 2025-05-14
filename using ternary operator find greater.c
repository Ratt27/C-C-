#include<stdio.h>
void main()
{
int a,b,c;
printf("  enter a number");
scanf (" %d",&a);
printf("  enter a number");
scanf (" %d",&b);
printf("  enter a number");
scanf (" %d",&c);
(a>c&&a>b)?printf("greater  is A"):(b>a&&b>c)?printf("greater is B"):(c>b&&c>a)?printf("greater is C"):printf("all numbers are equal");
	
}
