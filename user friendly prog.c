#include<stdio.h> 
void main()
{
	int  c;
	printf(" enter your choice among 1,2,3,4\n");
	printf("1= addition\n2=multiplication\n3= substraction\n4=division\n");
	printf("you can o for exit");
	scanf("%d",&c);
	int sum,ptd,result, R,a,b;
	while(1)
	{
		if(c==0)
		{
			break;
		}
		else
		{
			switch(c)
			{
				case 1:printf(" welcome to addition\n");
				printf("enter two number");
				scanf("%d",&a);
				scanf("%d",&b);
				sum=a+b;
				printf("the  result is %d",sum);
					printf(" enter your choice among 1,2,3,4\n");
	                printf("1= addition\n2=multiplication\n3= substraction\n4=division\n");
                    printf("you can o for exit");
	                scanf("%d",&c);  
				break;
			case 2: printf(" welcome to  multiplication\n");
				printf("enter two number");
				scanf("%d",&a);
				scanf("%d",&b);
                ptd=a*b;
				printf("the  result is %d",ptd);
					printf(" enter your choice among 1,2,3,4\n");
	                printf("1= addition\n2=multiplication\n3= substraction\n4=division\n");
                    printf("you can o for exit");
	                scanf("%d",&c);
				break;
			case 3:
			printf(" welcome to  substraction\n");
				printf("enter two number");
				scanf("%d",&a);
				scanf("%d",&b);
				result=a-b;
				printf("the  result is %d",result);
					printf(" enter your choice among 1,2,3,4\n");
	                printf("1= addition\n2=multiplication\n3= substraction\n4=division\n");
	                printf("you can o for exit");
	                scanf("%d",&c);
				break;
			case 4:
			printf(" welcome to division\n");
				printf("enter two number");
				scanf("%d",&a);
				scanf("%d",&b);
				R=a/b;
				printf("the  result is %d",R);
					printf(" enter your choice among 1,2,3,4\n");
	                printf("1= addition\n2=multiplication\n3= substraction\n4=division\n");
	                printf("you can o for exit");
	                scanf("%d",&c);
				break;
			
			}
		}
	}
}