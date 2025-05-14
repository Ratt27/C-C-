#include<iostream> 
using namespace std;
class multi 
{
	public :int display(int m);
	
};
int multi::display(int m)
{
	int i, ptd=0;
	cout<<"enter the value";
	cin>>m;
		for(i=1;i<=10;i++)
	{
		ptd=m*i;
		cout<<m<<"*"<<i<<"="<<ptd<< endl;
		
		
	}
	return (ptd);
}
int main()
{
	multi obj;
	
	int x,result;

	result=obj.display(x);
	return 0;
	
}