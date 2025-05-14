#include<iostream> 
using namespace std;
class marks
{
	public:
		int res;
		int value;
		marks(int x,int y,int z)
		{
			res=x+y+z;
		}
		marks(int t, int m)
		{
			value=t-m;
			
		}
};
int main()
{
	marks student1(77,78,98);
	marks student2(99,76,87);
	marks obj(67,87);
	cout<<student1.res<<"\n";
	cout<<student2.res<<"\n";
	cout<<obj.value<<"\n";
	return 0;
}