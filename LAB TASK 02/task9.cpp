#include<iostream>
using namespace std;

int main()
{
    int rows;

    cout<<"Enter number of rows: ";
    cin>>rows;

    int** elements=new int*[rows];

    int* elementsPerRow=new int[rows];

    for(int i=0;i<rows;i++)
    {
        cout<<"\nEnter number of elements of row "<<i+1<<" : ";
        cin>>elementsPerRow[i];

        elements[i]=new int[elementsPerRow[i]];

        for(int j=0;j<elementsPerRow[i];j++)
        {
            cout<<"\nElement "<<j+1<<" : ";
            cin>>elements[i][j];
        }
    }
    int maxElements=0;
    int maxRow=0;
    for(int i=0;i<rows;i++)
    {
        if(elementsPerRow[i]>maxElements)
        {
            maxElements=elementsPerRow[i];
            maxRow=i;
        }
    }
    cout << "\nThe row with maximum elements is row " << maxRow + 1 << endl;
    cout << "Size of that row: " << maxElements << endl;

    cout << "Elements of that row: ";

    for(int j=0; j<elementsPerRow[maxRow]; j++)
    {
    cout << elements[maxRow][j] << " ";
    }


    for(int i=0; i<rows; i++)
    {
        delete[] elements[i];
    }

    delete[] elements;
    delete[] elementsPerRow;

    elements=NULL;
    elementsPerRow=NULL;

    return 0;

    
}