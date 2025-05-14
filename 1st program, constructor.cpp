#include<iostream> 
using namespace std;
class marks
{
	public:
		int phy;
		int chem;
		int maths;
		marks(int x, int y, int z)
		{
		phy =x;
		chem =y;
		maths=z;	
		}
	
};
int main()
{
	marks student1(99,87,65);
	marks student2(78,89,76);
	cout<<student1.phy<<"****"<<student1.chem<<"****"<<student1.maths<<endl;
	cout<<student2.phy<<"***"<<student2.chem<<"****"<<student2.maths<<endl;
	return 0;
}