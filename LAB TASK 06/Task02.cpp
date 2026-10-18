#include <iostream>
using namespace std;

struct Runner
{
    int stamina;
    int speed;
};

bool canFollow(Runner curr, Runner next)
{
    return curr.stamina + curr.speed >= next.stamina;
}

void generateOrders(Runner runners[], int n, int order[], bool used[], int pos, double avg)
{
    if (pos == n)
    {
        cout << "Running order: ";

        for (int i = 0; i < n; i++)
        {
            cout << "R" << order[i] + 1 << " ";
        }

        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (used[i] == true)
        {
            continue;
        }

        if (pos > 0)
        {
            int prev = order[pos - 1];
            if (!canFollow(runners[prev], runners[i]))
            {
                continue;
            }

            if(canFollow(runners[i],runners[prev]))
            {
                continue;
            }
        }

        if (pos >= n - 2 && runners[i].stamina < avg)
        {
            continue;
        }
        order[pos] = i;
        used[i] = true;

        generateOrders(runners, n, order, used, pos + 1, avg);

        used[i] = false;
    }
}

int main()
{
    int n = 4;

    Runner runners[4] =
        {
            {10, 5},
            {13, 8},
            {7, 4},
            {15, 6}};

    int order[4];
    bool used[4] = {false};

    int totalStamina = 0;

    for (int i = 0; i < n; i++)
    {
        totalStamina += runners[i].stamina;
    }

    double avg = (double)totalStamina / n;

    cout << "Average stamina: " << avg << endl;

    generateOrders(runners, n, order, used, 0, avg);

    return 0;
}