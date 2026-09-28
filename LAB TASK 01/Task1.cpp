#include <iostream>
using namespace std;

void FindAverage(int *marks)
{
    int sum = 0;
    int highest = *marks;
    int lowest = *marks;

    for (int i = 0; i < 5; i++)
    {
        sum = sum + *(marks + i);

        if (*(marks + i) > highest)
        {
            highest = *(marks + i);
        }

        if (*(marks + i) < lowest)
        {
            lowest = *(marks + i);
        }
    }

    float average = sum / 5.0;

    cout << "Average marks: " << average << endl;
    cout << "Highest marks: " << highest << endl;
    cout << "Lowest marks: " << lowest << endl;
}

int main()
{
    int marks[5];

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter marks of student " << i + 1 << ": ";
        cin >> marks[i];
    }

    FindAverage(marks);

    return 0;
}