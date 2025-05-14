#include<iostream> 
using namespace std;
int Linear_Search (int arr[], int n, int key)
{
	int i;
	for (i=0;i<n;i++)
	{
		if(arr[i]== key)
		{
			return i;
		}
	}
	return -1;
};
int main ()
{
	 int n;
	 
	 cin>> n;
	 int arr[n];
	 for(int i=0; i<n;i++)
	 {
	 	cin>>arr[i];
	 }
	 int key ;
	 
	 
	 cin>> key;
	 cout<<Linear_Search(arr,n, key)<<endl;
	 return 0;
	 
	 
}