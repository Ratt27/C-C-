#include<iostream> 
using namespace std;
class  fact
{
	public:  void display(int s);
	
};

void fact:: display(int s)
{
	int f=1,i;
	for (i=1;i<=s;i++)
	{
		f=f*i;
	}
	cout<<"the factorial is "<<f;
	
}
int main()
{
	fact obj;
	int n;
	cout<<"enter the value of n";
	cin>>n;
	obj.display(n);
	return 0;
	
}