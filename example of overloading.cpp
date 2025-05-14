#include<iostream> 
using namespace std;
class abc 
{
	public :
		void display()
		{
			cout<<"default parameter"<<endl;
			
		}
		void display (int a, int b)
		{
			cout<<(a+b)<<endl;
		}
		void display(int a)
		{
			cout<<"the value of A"<<a<<endl;
		}
};
int main()

{
	abc objl;
	objl.display(10,20);
	objl.display();
	objl.display(20);
	return 0;
}