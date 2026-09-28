#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SLL
{
    Node *head;
    Node *tail;

public:
    SLL()
    {
        head = tail = nullptr;
    }

    void insertFront(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    void insertBack(int val)
    {
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;

            return;
        }

        tail->next = newNode;
        tail = newNode;
    }

    void insertPos(int pos, int val)
    {
        if (pos == 1)
        {
            insertFront(val);
            return;
        }

        Node *newNode = new Node(val);

        Node *temp;
        temp = head;

        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == nullptr)
            {
                cout << "\nInvalid position. ";
                delete newNode;
                return;
            }
            temp = temp->next;
        }

        if (temp == nullptr)
        {
            cout << "\nInvalid position. ";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == nullptr)
        {
            tail = newNode;
        }
    }

    void removeFront()
    {
        if (head == nullptr)
        {
            return;
        }

        Node *temp;
        temp = head;
        head = head->next;
        delete temp;

        if (head == nullptr)
        {
            tail = nullptr;
        }
    }

    void removeBack()
    {
        if (head == nullptr)
        {
            return;
        }

        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = nullptr;
        tail = temp;
    }

    void deletePos(int pos)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        if (pos == 1)
        {
            removeFront();
            return;
        }

        Node *temp;
        temp = head;

        for (int i = 1; i < pos - 1; i++)
        {
            if (temp->next == nullptr)
            {
                cout << "\nInvalid position. ";
                return;
            }

            temp = temp->next;
        }

        Node *deletenode = temp->next;

        if (deletenode == nullptr)
        {
            cout << "\nInvalid position.";
            return;
        }

        if (deletenode == tail)
        {
            tail = temp;
        }

        temp->next = deletenode->next;

        delete deletenode;
    }

    void display()
    {
        Node *temp = head;

        cout << "\nList: ";

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL";

        if (head != nullptr)
        {
            cout << "\nHead = " << head->data;
            cout << "\nTail = " << tail->data;
        }
        else
        {
            cout << "\nHead = NULL";
            cout << "\nTail = NULL";
        }

        cout << endl;
    }
};

int main()
{
    SLL list;
    int n;

    cout << "\nEnter number of values to be stored in linked list: ";
    cin >> n;


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
            list.insertFront(val);
        }
        else if (choice == 2)
        {
            list.insertBack(val);
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

    do
    {
        cout << "\n\n===== MENU =====";
        cout << "\n1. Remove Front";
        cout << "\n2. Remove Back";
        cout << "\n3. Insert at Position";
        cout << "\n4. Delete at Position";
        cout << "\n5. Display List";
        cout << "\n0. Exit";

        cout << "\n\nEnter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            list.removeFront();
            cout << "\nAfter removing front:";
            list.display();
        }

        else if (choice == 2)
        {
            list.removeBack();
            cout << "\nAfter removing back:";
            list.display();
        }

        else if (choice == 3)
        {
            int pos, val;

            cout << "\nEnter position: ";
            cin >> pos;

            cout << "Enter value: ";
            cin >> val;

            list.insertPos(pos, val);

            cout << "\nAfter insertion:";
            list.display();
        }

        else if (choice == 4)
        {
            int pos;

            cout << "\nEnter position to delete: ";
            cin >> pos;

            list.deletePos(pos);

            cout << "\nAfter deletion:";
            list.display();
        }

        else if (choice == 5)
        {
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

    return 0;
}