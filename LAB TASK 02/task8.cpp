#include<iostream>
using namespace std;

int main()
{
    int rows;

    cout<<"Enter number of rows: ";
    cin>>rows;

    string** seatingChart=new string*[rows];

    int* seatsPerRow=new int[rows];

    for(int i=0;i<rows;i++)
    {
        cout<<"\nEnter number of seats in row "<<i+1<<" : ";
        cin>>seatsPerRow[i];

        seatingChart[i]=new string[seatsPerRow[i]];
        cin.ignore();
        for(int j=0;j<seatsPerRow[i];j++)
        {
            cout<<"\nEnter name for seat "<<j+1<<" : ";
            // cin>>seatingChart[i][j];
            
            getline(cin,seatingChart[i][j]);
        }
    }

    cout<<"\n\nDISPLAYING SEATING CHART\n\n";

    for(int i=0;i<rows;i++)
    {
        cout<<"Row "<<i+1<<" : "<<endl;

        for(int j=0;j<seatsPerRow[i];j++)
        {
            cout<<seatingChart[i][j]<<" ";
        }

        cout<<endl;
    }

    for(int i=0;i<rows;i++)
    {
        delete[] seatingChart[i];
    }

    delete[] seatingChart;
    delete[] seatsPerRow;

    seatingChart=NULL;
    seatsPerRow=NULL;

    return 0;
}
