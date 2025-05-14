#include<iostream> 
using namespace std;
class multi 
{
	public : void display(int m);
	
};
 void multi::display(int m)
{
	int i, ptd=0;
	cout<<"enter the value";
	cin>>m;
		for(i=1;i<=10;i++)
	{
		ptd=m*i;
		cout<<m<<"*"<<i<<"="<<ptd<< endl;
		
		
	}

}
int main()
{
	multi obj;
	
	int x;


	obj.display(x);
	 return 0;
	
	
}