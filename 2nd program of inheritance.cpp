#include<iostream> 
using namespace std;
class Myclass
{
	public:
		void myFunction()
		{
			cout<<"some content in parent class";
			
		}
};
class MyOtherClass
{
	public:
		void myOtherFunction()
		{
			cout<<"some content in another class";
		}
};
class MyChildClass: public Myclass,
public MyOtherClass
{
	
};
int main()
{
MyChildClass myobj;
myobj.myFunction();
myobj.myOtherFunction();
return 0;
}