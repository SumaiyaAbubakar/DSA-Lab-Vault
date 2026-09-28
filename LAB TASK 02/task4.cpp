#include<iostream>
using namespace std;

int main()
{
	int r,c;
	cout<<"Enter number of rows: ";
	cin>>r;
	
	cout<<"Enter number of columns: ";
	cin>>c;
	
	int **arr;
	arr=new int*[r];
	
	for(int i=0;i<r;i++)
	{
		arr[i]=new int[c];
	}
	
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"\nElement matrix ["<<i<<"]"<<"["<<j<<"]:";
			cin>>arr[i][j];
		}
		
		cout<<"\n";
	}
	cout<<"The entered elements are: ";
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"\nElement matrix ["<<i<<"]"<<"["<<j<<"]:"<<arr[i][j];
			
		}
	}
	
	for(int k=0;k<r;k++)
	{
		delete[] arr[k];
	}
	
	delete arr;
	
	arr=NULL;
	
	return 0;
	
}
