#include<iostream> 
using namespace std;
class add
{
	public:int display(int a, int b);
};
int  add:: display(int a, int b)
{
	int c;
	cout<<"enter the value of A and B";
	cin>>a;
	cin>>b;
	c=a+b;
	cout<<"the result is "<<c;

}
int main()
{
	add obj;
	int x,y,z;

	
	z=obj.display(x,y);
	return 0;
}