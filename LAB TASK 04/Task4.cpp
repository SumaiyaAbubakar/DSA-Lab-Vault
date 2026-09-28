#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = nullptr;
    }
};

class DLL
{
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = tail = nullptr;
    }

    void insert(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;

            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void deletePos(int val)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        Node *temp = head;

        // Find the node
        while (temp != nullptr && temp->data != val)
        {
            temp = temp->next;
        }

        // Value not found
        if (temp == nullptr)
        {
            cout << "\nValue not found.";
            return;
        }

        // Only one node
        if (head == tail)
        {
            head = tail = nullptr;
        }

        // Delete head
        else if (temp == head)
        {
            head = head->next;
            head->prev = nullptr;
        }

        // Delete tail
        else if (temp == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }

        // Delete middle node
        else
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
    }

    void displayForward()
    {
        Node *temp = head;

        cout << endl;

        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout<<"NULL";
    }

    void displayBackword()
    {
        Node *temp = tail;

        cout << endl;

        cout<<"NULL<-";
        while (temp != nullptr)
        {
            cout << temp->data << "<-";
            temp = temp->prev;
        }
    }
};

int main()
{
    DLL list;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int val;

    for (int i = 1; i <= n; i++)
    {
        cout << "Enter value " << i << ": ";
        cin >> val;

        list.insert(val);
    }

    cout << "\nOriginal list (Forward): ";
    list.displayForward();

    cout << "\nOriginal list (Backward): ";
    list.displayBackword();

    cout << "\n\nEnter value to delete: ";
    cin >> val;

    list.deletePos(val);

    cout << "\nAfter deletion (Forward): ";
    list.displayForward();

    cout << "\nAfter deletion (Backward): ";
    list.displayBackword();

    return 0;
}