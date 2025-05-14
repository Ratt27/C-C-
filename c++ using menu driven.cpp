#include<iostream> 
using namespace std;
class menu
{
	public:void display(int ch);
};
void menu:: display(int ch)
{
int r1,r2,r3;
		cout<<"1. area of circle"<<endl;
        cout<<"2. area of square"<<endl;
        cout<<"3. area of rectangle"<<endl;
  		
  		cout<<"enter your choice";
  		cin>>ch;
	switch(ch)
  		{
		  	case 1:
		  		int rad;
		  		cout<<"enter the radius of the circle";
		  		cin>>rad;
		  		r1=3.14*rad*rad;
		  		cout<<"the area is "<<"\t"<<r1;
		  		break;
		  	case 2:
		  		int side;
		  		cout<<"enter the side of the square";
		  		cin>>side;
		  		r2=side*side;
		  		cout<<"the area is "<<"\t"<<r2;
		  		break;
		  	case 3:
		  		int l,b;
		  		cout<< "enter the length and width";
		  		cin>>l;
		  		cin>>b;
		  		r3=l*b;
		  		cout<<"the area is "<<"\t"<<r3;
		  
		  	default:
		  		break;

}
}
int main()
{
	
	menu obj;
	
	int x;

	
obj.display(x);
	 return 0;
		
}

	
