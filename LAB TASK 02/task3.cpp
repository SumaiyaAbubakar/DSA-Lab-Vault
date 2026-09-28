#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter size of array: ";
	cin>>n;
	
	int *arr;
	arr=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cout<<"\nElement "<<i+1<<": ";
		cin>>arr[i];
	}
	cout<<"\nThe entered elements are: ";
	for(int i=0;i<n;i++)
	{
		cout<<"\nElement "<<i+1<<": "<<arr[i];
		
	}
	
	delete[] arr;
	
	arr=NULL;
	
	return 0;
}
