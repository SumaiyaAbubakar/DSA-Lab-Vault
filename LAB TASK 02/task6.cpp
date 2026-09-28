//Tasks 2: Write a C++ program that dynamically allocates an integer array based on a size entered by the
//user. The program should:
//1. Take all elements from the user.
//2. Identify duplicate values.
//3. Create a new dynamic array containing only unique elements.
//4. Preserve the original order of elements.
//5. Display the original and resulting arrays.
//6. Properly deallocate both arrays.
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
	
	int unique=0;

	for(int i=0;i<n;i++)
	{
		bool dup=false;
		for(int j=0;j<i;j++)
		{
			if(arr[i]==arr[j])
			{
				dup=true;
				break;
			}		
		}
		if(!dup)
			{
				unique++;
			}
	}
	
	int *newarr;
	newarr=new int[unique];
	int k=0;
	for(int i=0;i<n;i++)
	{
		bool dup=false;
		for(int j=0;j<i;j++)
		{
			if(arr[i]==arr[j])
			{
				dup=true;
				break;
			}			
		}
		if(!dup)
			{
				newarr[k]=arr[i];
				k++;
			}
	}
	cout<<"\nUnique elements: \n";
	for(int i=0;i<unique;i++)
	{
		cout<<newarr[i]<<endl;
	}
	
	
	
	delete[] arr;
	delete[] newarr;
	
	arr=NULL;
	newarr=NULL;
	
	return 0;
}
