
#include <iostream>
#include <string>
using namespace std;

int N, targetSum;
string targetCode;
string code = "";

bool used[10] = {false};
bool found = false;
bool anyValid = false;

void generate(int position, int sum);
void tryDigit(int digit, int position, int sum);

void tryDigit(int digit, int position, int sum)
{
    
    if (digit > 9)
    {
        return;
    }

    if (!(position == 0 && digit == 0) && !used[digit])
    {
        used[digit] = true;
        code = code + char('0' + digit);

        generate(position + 1, sum + digit);

        code.pop_back();
        used[digit] = false;
    }

    tryDigit(digit + 1, position, sum);
}

void generate(int position, int sum)
{

    if (position == N)
    {
        if (sum == targetSum)
        {
            cout << code << endl;
            anyValid = true;

            if (code == targetCode)
            {
                found = true;
            }
        }

        return;
    }

    tryDigit(0, position, sum);
}

int main()
{
    cout << "Enter number of positions: ";
    cin >> N;

    if (N < 1 || N > 10)
    {
        cout << "N must be between 1 and 10." << endl;
        return 0;
    }

    cout << "Enter target sum: ";
    cin >> targetSum;

    cout << "Enter target code: ";
    cin >> targetCode;

    cout << "\nValid lock codes:\n";

    generate(0, 0);

    if (!anyValid)
    {
        cout << "No valid codes found." << endl;
    }

    if (found)
    {
        cout << "Target code is among the valid codes." << endl;
    }
    else
    {
        cout << "Target code is NOT among the valid codes." << endl;
    }

    return 0;
}
