#include <iostream>
using namespace std;

class Numbers
{
    int size;
    int* arr;

public:

    // Constructor
    Numbers(int n)
    {
        size = n;
        arr = new int[size];
    }

    // Copy Constructor - Deep Copy
    Numbers(const Numbers& orig)
    {
        size = orig.size;

        arr = new int[size];

        for(int i = 0; i < size; i++)
        {
            arr[i] = orig.arr[i];
        }
    }

    // Assignment Operator - Deep Copy
    Numbers& operator=(const Numbers& orig)
    {
        if(this != &orig)
        {
            delete[] arr;

            size = orig.size;

            arr = new int[size];

            for(int i = 0; i < size; i++)
            {
                arr[i] = orig.arr[i];
            }
        }

        return *this;
    }

    // Assign values
    void AssignValues()
    {
        for(int i = 0; i < size; i++)
        {
            cout << "Value " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    // Display values
    void displayValues()
    {
        cout << "Displaying values: ";

        for(int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }

        cout << endl;
    }

    // Destructor
    ~Numbers()
    {
        delete[] arr;
    }
};

int main()
{
    // First object
    Numbers obj1(5);

    cout << "Enter values for Object 1:\n";
    obj1.AssignValues();

    cout << "\nObject 1: ";
    obj1.displayValues();


    // Copy Constructor
    cout << "\nCreating Object 2 using Object 1...\n";

    Numbers obj2(obj1);

    cout << "Object 2 after copying: ";
    obj2.displayValues();


    // Modify Object 2
    cout << "\nEnter new values for Object 2:\n";
    obj2.AssignValues();

    cout << "\nAfter modifying Object 2:\n";

    cout << "Object 1: ";
    obj1.displayValues();

    cout << "Object 2: ";
    obj2.displayValues();


    // Assignment Operator
    cout << "\nCreating Object 3...\n";

    Numbers obj3(5);

    obj3 = obj1;

    cout << "Object 3 after assignment from Object 1: ";
    obj3.displayValues();


    return 0;
}