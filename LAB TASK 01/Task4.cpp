#include <iostream>
using namespace std;

int main()
{
    int n;
    int *arr;
    int sum = 0;
    float avg = 0.0;

    cout << "Enter size of an array: ";
    cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter value of element " << i + 1 << ":";
        cin >> *(arr + i);

        sum = sum + *(arr + i);
    }

    avg = (float)sum / n;

    cout << "Average is : " << avg;

    delete[] arr;
}