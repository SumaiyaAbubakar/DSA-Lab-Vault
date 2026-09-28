#include <iostream>
#include <cstring>
using namespace std;

class Text
{
    char* sentence;
    int n;

public:

    // Constructor
    Text(int n)
    {
        this->n = n;
        sentence = new char[n + 1];

        cout << "Write Sentence: ";
        cin.getline(sentence, n + 1);
    }

    // Copy Constructor - Deep Copy
    Text(const Text& orig)
    {
        n = orig.n;

        sentence = new char[n + 1];

        strcpy(sentence, orig.sentence);
    }

    // Assignment Operator - Deep Copy
    Text& operator=(const Text& orig)
    {
        if (this != &orig)
        {
            delete[] sentence;

            n = orig.n;

            sentence = new char[n + 1];

            strcpy(sentence, orig.sentence);
        }

        return *this;
    }

    // Function to modify sentence
    void modify()
    {
        cout << "\nEnter new sentence: ";
        cin.ignore();
        cin.getline(sentence, n + 1);
    }

    // Display
    void displaySentence()
    {
        cout << "The written sentence is: "
             << sentence << endl;
    }

    // Destructor
    ~Text()
    {
        delete[] sentence;
    }
};

int main()
{
    Text obj1(50);

    cout << "\nObject 1: ";
    obj1.displaySentence();

    // Copy constructor
    Text obj2(obj1);

    cout << "\nObject 2 after copying from Object 1: ";
    obj2.displaySentence();

    // Modify obj1
    obj1.modify();

    cout << "\nAfter modifying Object 1:\n";

    cout << "Object 1: ";
    obj1.displaySentence();

    cout << "Object 2: ";
    obj2.displaySentence();

    return 0;
}