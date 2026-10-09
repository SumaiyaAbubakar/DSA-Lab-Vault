#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNo;
    string name;
    int score;
};

void selectionSort(Student st[],int size)
{
    int smallest_idx=0;

    for(int i=0;i<size-1;i++)
    {
        smallest_idx=i;

        for(int j=i+1;j<size;j++)
        {
            if(st[j].score>st[smallest_idx].score || (st[j].score==st[smallest_idx].score && (st[j].score<st[smallest_idx].score)))
            {
                smallest_idx=j;
            }
        }

        swap(st[i],st[smallest_idx]);
    }
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    Student students[100];

    // 1. Input students
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter details of student " << i + 1 << endl;

        cout << "Roll Number: ";
        cin >> students[i].rollNo;

        cout << "Name: ";
        cin >> students[i].name;

        cout << "Score: ";
        cin >> students[i].score;
    }

    // 2. Insertion Sort
    // Descending score
    // If scores are equal, smaller roll number first

    for (int i = 1; i < n; i++)
    {
        Student curr = students[i];
        int prev = i - 1;

        while (prev >= 0 &&
              (students[prev].score < curr.score ||
              (students[prev].score == curr.score &&
               students[prev].rollNo > curr.rollNo)))
        {
            students[prev + 1] = students[prev];
            prev--;
        }

        students[prev + 1] = curr;
    }

    // Display sorted list
    cout << "\n----- Merit List -----\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Position: " << i + 1 << endl;
        cout << "Roll No: " << students[i].rollNo << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Score: " << students[i].score << endl;
        cout << endl;
    }

    // 3. Ask for roll number
    int searchRoll;

    cout << "Enter roll number to search: ";
    cin >> searchRoll;

    // 4. Binary Search
    int left = 0;
    int right = n - 1;
    int found = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (students[mid].rollNo == searchRoll)
        {
            found = mid;
            break;
        }
        else if (students[mid].rollNo < searchRoll)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    // 5. Display result
    if (found != -1)
    {
        cout << "\n----- Student Found -----\n";
        cout << "Name: " << students[found].name << endl;
        cout << "Score: " << students[found].score << endl;
        cout << "Position: " << found + 1 << endl;
    }
    else
    {
        cout << "\nStudent Not Found" << endl;
    }

    return 0;
}