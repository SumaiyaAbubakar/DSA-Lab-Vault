#include <iostream>
#include <string>
using namespace std;

struct Parcel
{
    int trackingID;
    string customerName;
    int distance;
};

void insertionSort(Parcel p[], int size);
void displaySorted(Parcel p[], int size);

void insertionSort(Parcel p[], int size)
{
    for (int i = 1; i < size; i++)
    {
        Parcel curr = p[i];
        int prev = i - 1;

        while (prev >= 0 && (p[prev].distance > curr.distance || (p[prev].distance == curr.distance && p[prev].trackingID > curr.trackingID)))
        {
            p[prev + 1] = p[prev];
            prev--;
        }

        p[prev + 1] = curr;
    }
}

void displaySorted(Parcel p[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "\nParcel " << i + 1 << " : ";
        cout << p[i].customerName << " " << p[i].distance << " " << p[i].trackingID;
    }
}

int main()
{
    int n;

    cout << "\nEnter number of parcels : ";
    cin >> n;

    Parcel p[n];

    cout << "\nEnter details of each parcel : ";

    for (int i = 0; i < n; i++)
    {
        cout << "\nParcel " << i + 1;

        cout << "\nTracking id : ";
        cin >> p[i].trackingID;

        cout << "\nCustomer name : ";
        cin >> p[i].customerName;

        cout << "\nDistance : ";
        cin >> p[i].distance;
    }

    insertionSort(p, n);
    displaySorted(p, n);

    int d;

    cout << "\nEnter distance to search : ";
    cin >> d;

    int left = 0;
    int right = n - 1;
    int found = -1;
    int mid;

    while (left <= right)
    {
        mid = left + (right - left) / 2;

        if (p[mid].distance == d)
        {
            found = mid;
            break;
        }

        if (p[mid].distance < d)
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
        cout << "\n\nParcel found:";
        cout << "\nTracking ID: " << p[found].trackingID;
        cout << "\nCustomer Name: " << p[found].customerName;
        cout << "\nDistance: " << p[found].distance;
    }
    else
    {
        cout << "\n\nNo parcel found with this distance.";
    }

    return 0;
}
