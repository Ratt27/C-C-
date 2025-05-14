#include<iostream> 
using namespace std; 
class abc
{
	public :
		void display ()
		{
			cout<<"My name is Rattriz"<<endl;
			
		}
};
class bbc :public abc
{
	public:
		void display()
		{
			cout<<"My name is   kim taehyung";
		}
};
int main()
{
	bbc obj1;
	obj1.display();
	return 0;
}