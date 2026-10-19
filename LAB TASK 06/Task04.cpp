#include <iostream>
using namespace std;

const int rows = 4;
const int cols = 4;

int people[rows][cols] = {
    {8, 12, -1, 6},
    {5, 10, 7, -1},
    {-1, 9, 15, 4},
    {6, -1, 8, 11}};

int units[rows][cols] = {
    {2, 3, -1, 2},
    {1, 3, 2, -1},
    {-1, 2, 4, 1},
    {2, -1, 2, 3}};

bool highRisk[rows][cols] = {
    {1, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1}};

int capacity;
int unitsUsed = 0;
int totalPeople = 0;
int bestPeople = 0;
int bestunits = 0;
int highRiskCount = 0;
bool foundSolution = false;

bool selected[rows][cols] = {false};
bool bestSelected[rows][cols] = {false};

bool checkRows()
{
    for (int i = 0; i < rows; i++)
    {
        bool hasPeople = false;
        bool hasSelection = false;

        for (int j = 0; j < cols; j++)
        {
            if (people[i][j] != -1)
            {
                hasPeople = true;
            }

            if (selected[i][j] == true)
            {
                hasSelection = true;
            }
        }

        if (hasPeople && !hasSelection)
        {
            return false;
        }
    }

    return true;
}
void backtrack(int idx)
{
    if (idx == rows * cols)
    {
        if (checkRows() && (!foundSolution || totalPeople > bestPeople))
        {
            foundSolution = true;
            bestPeople = totalPeople;
            bestunits = unitsUsed;

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    bestSelected[i][j] = selected[i][j];
                }
            }
        }
        return;
    }

    int row = idx / cols;
    int col = idx % cols;

    if (people[row][col] == -1)
    {
        backtrack(idx + 1);
        return;
    }

    int extraUnit = 0;

    if (highRisk[row][col] == 1 && highRiskCount == 1)
    {
        extraUnit = 1;
    }

    if (unitsUsed + units[row][col] + extraUnit <= capacity)
    {
        selected[row][col] = true;
        unitsUsed = unitsUsed + units[row][col] + extraUnit;
        totalPeople = totalPeople + people[row][col];

        if (highRisk[row][col] == 1)
        {
            highRiskCount++;
        }

        backtrack(idx + 1);

        selected[row][col] = false;
        unitsUsed = unitsUsed - units[row][col] - extraUnit;
        totalPeople = totalPeople - people[row][col];

        if (highRisk[row][col] == 1)
        {
            highRiskCount--;
        }
    }

    backtrack(idx + 1);
}
int main()
{
    cout << "\bPeople matrix: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << people[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nRescue units matrix: ";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << units[i][j] << " ";
        }

        cout << endl;
    }

    cout << "\nEnter rescue unit capacity: ";
    cin >> capacity;

    // ADDITION 2: Start backtracking from the first cell
    backtrack(0);

    if (!foundSolution)
    {
        cout << "\nNo valid allocation exists." << endl;
    }
    else
    {
        cout << "\nSelected areas (row, column): ";

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (bestSelected[i][j] == true)
                {
                    cout << "(" << i + 1 << ", " << j + 1 << ") ";
                }
            }
        }

        cout << "\nTotal people rescued: " << bestPeople;
        cout << "\nTotal rescue units used: " << bestunits;
        cout << "\nRemaining rescue units: " << capacity - bestunits;
    }

    return 0;
}