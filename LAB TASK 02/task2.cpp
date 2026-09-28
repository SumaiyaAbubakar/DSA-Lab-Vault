#include<iostream>
using namespace std;

int main()
{
	int matrix[2][3];
	
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\nElement matrix ["<<i<<"]"<<"["<<j<<"]:";
			cin>>matrix[i][j];
		}
		
		cout<<"\n";
	}
	cout<<"The entered elements are: ";
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<3;j++)
		{
			cout<<"\nElement matrix ["<<i<<"]"<<"["<<j<<"]:"<<matrix[i][j];
			
		}
	}
	
	return 0;
}
