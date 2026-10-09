#include <iostream>
// #include<vector>
using namespace std;

void selectionSort(int arr[], int size);

int main()
{
    int arr[6];

    cout << "\nEnter medicine ids : ";

    for (int i = 0; i < 6; i++)
    {
        cout << "\nEnter id " << i + 1 << " : ";
        cin >> arr[i];
    }

    selectionSort(arr, 6);

    int searchId;
    cout << "\nEnter id to search : ";
    cin >> searchId;

    int left = 0;
    int right = 5;
    int found = -1;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (arr[mid] == searchId)
        {
            found = mid;
            break;
        }

        else if (arr[mid] < searchId)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1;
        }
    }

    if (found != -1)
    {
        cout << "\nFound at index : " << found;
    }

    else
    {
        cout << "\nMedicine unavailable. ";
    }


    return 0;
}

void selectionSort(int arr[], int size)
{
    int smallest_idx;

    for (int i = 0; i < size - 1; i++)
    {
        smallest_idx = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[smallest_idx])
            {
                smallest_idx = j;
            }
        }

        swap(arr[i], arr[smallest_idx]);
    }
}
