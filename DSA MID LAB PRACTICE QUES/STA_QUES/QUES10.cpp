#include <iostream>
#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    int severity;
};

class QueueNode
{
public:
    Patient p;
    QueueNode *next;

    QueueNode(Patient x)
    {
        p = x;
        next = nullptr;
    }
};

class Queue
{
    QueueNode *front;
    QueueNode *rear;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(Patient p)
    {
        QueueNode *newNode = new QueueNode(p);

        if (front == nullptr)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    Patient dequeue()
    {
        if (front == nullptr)
        {
            return Patient{-1, "", -1};
        }

        Patient p = front->p;

        QueueNode *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        return p;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }
};

class Node
{
public:
    Patient p;
    Node *next;
    Node *prev;

    Node(Patient x)
    {
        p = x;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL
{
    Node *head;
    Node *tail;

public:
    DLL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void insertPatient(Patient p)
    {
        Node *newNode = new Node(p);

        if (head == nullptr)
        {
            head = tail = newNode;
            return;
        }

        if (p.severity > head->p.severity)
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != nullptr && temp->next->p.severity >= p.severity)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
        {
            temp->next->prev = newNode;
        }
        else
        {
            tail = newNode;
        }

        temp->next = newNode;
    }

    void displayForward()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->p.name << " ";

            temp = temp->next;
        }
    }
    void displayBackward()
    {
        Node *temp = tail;

        while (temp != nullptr)
        {
            cout << temp->p.name << " ";

            temp = temp->prev;
        }
    }
};