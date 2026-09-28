#include<iostream>
using namespace std;

int main()
{
	int arr[5];
	for(int i=0;i<5;i++)
	{
		cout<<"\nElement "<<i+1<<": ";
		cin>>arr[i];
	}
	cout<<"\nThe entered elements are: ";
	for(int i=0;i<5;i++)
	{
		cout<<"\nElement "<<i+1<<": "<<arr[i];
		
	}
	return 0;
	
}
