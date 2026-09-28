//Tasks 3: You are tasked with developing a program to manage and display the Grade Point Average
//(GPA) for the core courses offered in the first semester of four departments: Software Engineering (SE),
//Artificial Intelligence (AI), Computer Science (CS), and Data Science (DS). Each department offers a
//distinct number of core courses for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2
//core courses, and DS has 1 core course. To efficiently store and present this data, which type of array
//structure would you employ? implement a solution using the chosen array structure to display the GPAs
//of the core courses for each department.

#include<iostream>
using namespace std;

int main()
{
	int dept=4;
	int **arr=new int *[dept];
	int size[4];
	
	for(int i=0;i<dept;i++)
	{
		cout<<"\nEnter size of dept "<<i+1<<": ";
		cin>>size[i];
		
		arr[i]=new int[size[i]];
	}
	
	for(int i=0;i<dept;i++)
	{
		cout<<"\nEnter gpa of "<< size[i] <<" core courses for dept "<<i+1<<": ";
		for(int j=0;j<size[i];j++)
		{
			cout<<"\nCore Course "<<j+1<<" : ";
			cin>>arr[i][j];
		}
	}
	
	cout<<"\n\nThe entered data is : ";
	for(int i=0;i<dept;i++)
	{
		cout<<"\nDept "<<i+1<<": ";
		
		for(int j=0;j<size[i];j++)
		{
			cout<<arr[i][j]<<" ";
		}
		
		cout<<endl;
	}
	
	for(int i=0;i<dept;i++)
	{
		delete[] arr[i];
	}
	
	delete[] arr;
	
	return 0;
}
