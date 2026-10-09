#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string stopName;
    Node *next;
    Node *prev;
    Node()
    {
        stopName = " ";
        next = prev = nullptr;
    }
    Node(string n)
    {
        stopName = n;
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
        head = nullptr;
        tail = nullptr;
    }

    void addHead(string stop)
    {
        Node *newNode = new Node(stop);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;

            head->prev = head;
            head->next = head;

            return;
        }

        newNode->next = head;
        head->prev = newNode;

        head = newNode;

        head->prev = tail;
        tail->next = head;
    }

    void addTail(string stop)
    {
        Node *newNode = new Node(stop);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
            head->prev = head;
            head->next = head;

            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;

        tail->next = head;
        head->prev = tail;
    }

    void addStop(string stop, int pos)
    {
        if (pos == 1)
        {
            addHead(stop);
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
        }

        if (temp == tail)
        {
            addTail(stop);
            return;
        }

        Node *newNode = new Node(stop);

        newNode->next = temp;
        temp->prev->next = newNode;
        newNode->prev = temp->prev;
        temp->prev = newNode;
    }

    void delHead()
    {

        Node *temp = head;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }

        delete temp;
    }

    void delTail()
    {
        Node *temp = tail;
        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
        }

        delete temp;
    }

    void removeStop(int pos)
    {
        if (pos == 1)
        {
            delHead();
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos; i++)
        {

            temp = temp->next;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        delete temp;
    }

    void moveForward(string stop, int steps)
    {
        Node *temp = head;

        bool found = 0;
        do
        {
            if (temp->stopName == stop)
            {

                found = 1;
                break;
            }
            else
            {
                temp = temp->next;
            }
        } while (temp != head);

        if (found != 0)
        {

            for (int i = 1; i <= steps; i++)
            {
                cout << "\n"
                     << temp->stopName;
                temp = temp->next;
            }
        }
    }

    void moveBackward(string stop, int steps)
    {
        Node *temp = tail;

        bool found = 0;
        do
        {
            if (temp->stopName == stop)
            {

                found = 1;
                break;
            }
            else
            {
                temp = temp->prev;
            }
        } while (temp != tail);

        if (found != 0)
        {

            for (int i = 1; i <= steps; i++)
            {
                cout << "\n"
                     << temp->stopName;
                temp = temp->prev;
            }
        }
    }
};