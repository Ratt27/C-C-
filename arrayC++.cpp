#include<iostream> 
using namespace std;
class daigonal
{
	public:void display(int a[3][3]);
		
};
void daigonal:: display(int a[3][3])
{
	
	int s1=0, s2=0,i,j;

		for (i=0;i<3;i++)
     	{
		for (j=0;j<3;j++)
		{
			if(i==j)
			{
				s1+=a[i][j];	
			}
			if ((i+j)==2)
			{
				s2+=a[i][j];
			}
			
			
		}
       }
        cout<<"the sum of the major daigonal is"<<"\t"<<s1;
        cout<<"the sum of the minor daigonal is "<<"\t"<<s2;
}
int main()
{
	daigonal obj;
	
	int x[3][3],i,j;
	cout<<"enter the value of x";
		for (i=0;i<3;i++)
     	{
		for (j=0;j<3;j++)
		{
			cin>>x[i][j];	
		}
		 }
	
		
		
		
	
	obj.display(x);
	
	
	

	

	 return 0;
		
}