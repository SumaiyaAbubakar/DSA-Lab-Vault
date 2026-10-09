#include <iostream>
using namespace std;

class Participant
{
public:
    int Part_ID;
    int score;
    int n;

    Participant()
    {
        Part_ID = 0;
        score = 0;
        n = 0;
    }
    Participant(int id, int sc)
    {
        Part_ID = id;
        score = sc;
        n = 0;
    }
};

class Node
{
public:
    Participant part;
    Node *next;
    Node *prev;

    Node(Participant p)
    {
        part = p;
        next = nullptr;
        prev = nullptr;
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

    void deleteHead()
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        if(head==tail)
        {
            delete head;
            head=nullptr;
            tail=nullptr;

            return;
        }

        Node *temp = head;
        head = head->next;
        head->prev = tail;
        tail->next = head;
        delete temp;
    }

    void deleteTail()
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        if(head==tail)
        {
            delete head;
            head=nullptr;
            tail=nullptr;

            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;

        delete temp;
    }

    void deletePos(Node *node)
    {
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }

        Node *nodetodel = node;

        if (nodetodel == tail)
        {
            deleteTail();
            return;
        }

        if (nodetodel == head)
        {
            deleteHead();
            return;
        }

        nodetodel->prev->next = nodetodel->next;
        nodetodel->next->prev = nodetodel->prev;

        delete nodetodel;
    }

    void traverse() // examine
    {
        if(head==nullptr)
        {
            cout<<"\nList is empty. ";
            return;
        }
        Node *temp = head;

        do
        {
            temp->part.n++;
            if (temp->part.n == 3)
            {
                Node *nextPosition;

                if (temp->part.score % 2 == 0)
                {
                    nextPosition = temp->next->next;
                }
                else
                {
                    nextPosition = temp->prev->prev;
                }

                deletePos(temp);

                if(head!=tail)
                {
                    temp=nextPosition;
                }
            }

            else
            {
                if ((temp->part.score) % 2 == 0)
                {

                    temp = temp->next->next;
                }

                else
                {
                    temp = temp->prev->prev;
                }
            }

        }

        while (head!=tail);
    }
};
