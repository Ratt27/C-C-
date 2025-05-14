#include<stdio.h> 
struct student
{
	int rollno;
	char name[20];
	float marks;
};
void main()
{
	struct student s1={1,"jenny",90};
	struct student s2={2,"jiya",85};
	
	printf("info for s1");
	printf("\n%d %s %f",s1.rollno,s1.name,s1.marks);
	printf("\ninfo for s2");
	printf("\n %d %s %f",s2.rollno,s2.name,s2.marks);
	
}