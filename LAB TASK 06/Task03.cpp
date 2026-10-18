#include <iostream>
#include <string>
using namespace std;

struct Student
{
    string name;
    string category;
    int priority;
    int minTokens;
    int maxTokens;
    int allocated;
};
bool checkStudentRestriction(Student students[])
{
    return students[0].allocated > students[1].allocated;
}

bool AllocateTokens(Student students[], int n, int index, int threshold, int totalTokens)
{
    if (index == n)
    {
        return checkPriorityTotal(students, n, threshold) && CheckMinMax(students, n) && CheckTokenSupply(students, n, totalTokens)  && checkCategoryLimit(students, n) && checkStudentRestriction(students);
    }

    for (int t = students[index].minTokens; t <= students[index].maxTokens; t++)
    {
        students[index].allocated = t;

        bool valid = true;

        for (int j = 0; j < index; j++)
        {
            if (students[j].category == students[index].category && students[j].allocated == t)
            {
                valid = false;
                break;
            }

            if (students[j].priority == 1 && students[index].priority == 0 && students[j].allocated < t)
            {
                valid = false;
                break;
            }

            if (students[j].priority == 0 && students[index].priority == 1 && students[j].allocated > t)
            {
                valid = false;
                break;
            }
        }

        if (valid)
        {
            if (AllocateTokens(students, n, index + 1, threshold, totalTokens))
            {
                return true;
            }
        }

        students[index].allocated = 0;
    }

    return false;
}

bool checkPriorityTotal(Student students[], int n, int threshold)
{
    int hightotal = 0;
    int lowtotal = 0;

    for (int i = 0; i < n; i++)
    {
        if (students[i].priority == 1)
        {
            hightotal = hightotal + students[i].allocated;
        }
        else
        {
            lowtotal = lowtotal + students[i].allocated;
        }
    }

    return hightotal - lowtotal >= threshold;
}

bool CheckMinMax(Student students[], int n)
{
    bool minFound=false;
    bool maxFound=false;
    
    for(int i=0;i<n;i++)
    {
        if(students[i].allocated==students[i].minTokens)
        {
            minFound=true;
        }

        if(students[i].allocated==students[i].maxTokens)
        {
            maxFound=true;
        }
    }

    return maxFound && minFound;
}

bool CheckTokenSupply(Student students[], int n, int totalTokens)
{
    int totalAllocated=0;

    for(int i=0;i<n;i++)
    {
        totalAllocated=totalAllocated+students[i].allocated;
    }

    return totalAllocated<=totalTokens;
}

void displayCategoryTotals(Student students[], int n)
{
    int breakfast = 0;
    int lunch = 0;
    int dinner = 0;

    for (int i = 0; i < n; i++)
    {
        if (students[i].category == "Breakfast")
        {
            breakfast += students[i].allocated;
        }
        else if (students[i].category == "Lunch")
        {
            lunch += students[i].allocated;
        }
        else if (students[i].category == "Dinner")
        {
            dinner += students[i].allocated;
        }
    }

    cout << "Breakfast total: " << breakfast << endl;
    cout << "Lunch total: " << lunch << endl;
    cout << "Dinner total: " << dinner << endl;
}

bool checkCategoryLimit(Student students[], int n)
{
    int breakfast = 0;

    for (int i = 0; i < n; i++)
    {
        if (students[i].category == "Breakfast")
        {
            breakfast += students[i].allocated;
        }
    }

    return breakfast <= 5;
}

int main()
{
    const int n = 4;

    Student students[n] =
    {
        {"S1", "Breakfast", 1, 2, 5, 0},
        {"S2", "Breakfast", 0, 1, 4, 0},
        {"S3", "Lunch",     1, 2, 5, 0},
        {"S4", "Dinner",    0, 1, 3, 0}
    };

    int threshold = 2;
    int totalTokens = 10;

    // Find the maximum possible allocation
    int maxPossible = 0;

    for (int i = 0; i < n; i++)
    {
        maxPossible += students[i].maxTokens;
    }

    int maxEmergency = maxPossible - totalTokens;

    if (maxEmergency < 0)
    {
        maxEmergency = 0;
    }

    // Try emergency amounts from smallest to largest
    bool found = false;
    int emergencyUsed = 0;

    for (int e = 0; e <= maxEmergency; e++)
    {
        if (AllocateTokens(students, n, 0,
                           threshold, totalTokens + e))
        {
            found = true;
            emergencyUsed = e;
            break;
        }
    }

    // Display the result
    if (found)
    {
        cout << "\nValid allocation found!" << endl;

        cout << "\nStudent Allocations:" << endl;

        int totalAllocated = 0;

        for (int i = 0; i < n; i++)
        {
            cout << students[i].name << " ("
                 << students[i].category << "): "
                 << students[i].allocated
                 << " tokens" << endl;

            totalAllocated += students[i].allocated;
        }

        cout << "\nCategory Totals:" << endl;
        displayCategoryTotals(students, n);

        cout << "\nEmergency tokens used: "
             << emergencyUsed << endl;

        cout << "Unused tokens: "
             << totalTokens + emergencyUsed - totalAllocated
             << endl;
    }
    else
    {
        cout << "No valid allocation found!" << endl;
    }

    return 0;
}