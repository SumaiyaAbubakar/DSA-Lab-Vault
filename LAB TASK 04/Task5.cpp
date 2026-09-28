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

class CDLL
{
    Node *head;
    Node *tail;

public:
    CDLL()
    {
        head = tail = nullptr;
    }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
            return;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;
        tail->next = head;
        head->prev = tail;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = tail = newNode;
            newNode->next = head;
            newNode->prev = tail;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        tail->next = head;
        head->prev = tail;
    }

    void moveForward(int pos)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        if (pos < 1 || pos > getCount())
        {
            cout << "\nInvalid node. ";
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        cout << "\nNode at position " << pos << " : " << temp->data << endl;
    }

    int getCount()
    {
        int count = 0;
        Node *temp = head;

        if (head == nullptr)
        {
            return 0;
        }

        do
        {
            count++;
            temp = temp->next;
        } while (temp != head);

        return count;
    }
    void moveBackward(int pos)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        if (pos < 1 || pos > getCount())
        {
            cout << "\nInvalid node. ";
            return;
        }

        Node *temp = tail;
        for (int i = getCount(); i > pos; i--)
        {
            temp = temp->prev;
        }

        cout << "\nNode at position " << pos << " : " << temp->data << endl;
    }

    void display()
    {
        Node *temp = head;
        cout << "\n";

        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        while (temp != head);
    }
};

int main()
{
    CDLL list;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int val;

    for (int i = 1; i <= n; i++)
    {
        int val, choice;

        cout << "\nEnter value " << i << ": ";
        cin >> val;

        cout << "1. Insert at Front";
        cout << "\n2. Insert at Back";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            list.insertAtHead(val);
        }
        else if (choice == 2)
        {
            list.insertAtTail(val);
        }
        else
        {
            cout << "Invalid choice. Value not inserted.\n";
            i--;
        }
    }

    cout << "\n\n===== INITIAL LIST =====";
    list.display();

    int choice;
    int pos;

    do
    {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Move forward";
        cout << "\n2. Move backward";
        cout << "\n0. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter position : ";
            cin >> pos;
            list.moveForward(pos);
            cout << "\nAfter moving forward:";
            list.display();
        }

        else if (choice == 2)
        {
            cout << "\nEnter position : ";
            cin >> pos;
            list.moveBackward(pos);
            cout << "\nAfter moving back:";
            list.display();
        }

        else if (choice == 0)
        {
            cout << "\nProgram ended.";
        }

        else
        {
            cout << "\nInvalid choice.";
        }

    } while (choice != 0);
}