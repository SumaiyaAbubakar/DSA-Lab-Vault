#include <iostream>
using namespace std;

class Guard
{
public:
    int guard_id;
    int security_lvl;

    Guard() {}
    Guard(int id, int l)
    {
        guard_id = id;
        security_lvl = l;
    }
};

class Node
{
public:
    Guard grd;
    Node *next;
    Node *prev;

    Node(Guard g)
    {
        grd = g;
        next = prev = nullptr;
    }
};

// class Queue
// {
//     Node* front;
//     Node* rear;
//     int count;

//     public:
//     Queue()
//     {
//         front=rear=nullptr;
//         count=0;
//     }

//     void enqueue()
//     {
//         if()
//     }
// };

class CLL
{
    Node *head;
    Node *tail;

public:
    CLL()
    {
        head = tail = nullptr;
    }

    int count()
    {
        int count = 0;

        Node *temp = head;

        do
        {
            count++;
            temp = temp->prev;

        } while (temp != head);

        return count;
    }
    void inspect()
    {
        Node *temp = head;
        Node *ahead = nullptr;
        int noExchange = 0;

        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }

        do
        {
            ahead = temp->next->next;

            if (ahead->grd.security_lvl > temp->grd.security_lvl)
            {
 
                Node *temp2 = ahead->prev;
                Node *after = ahead->next;

                bool wasTail = (temp == tail);

                if (count() == 3)
                {
                    ahead->next = temp2;
                    temp2->prev = ahead;

                    temp2->next = temp;
                    temp->prev = temp2;

                    temp->next = ahead;
                    ahead->prev = temp;

                    if (temp == head)
                    {
                        head = ahead;
                        tail = temp;
                    }

                    else if (temp == tail)
                    {
                        tail = ahead;
                    }

                    else
                    {
                        tail = temp;
                    }

                    head->prev = tail;
                    tail->next = head;

                    temp = temp2;
                    noExchange = 0;
                }
                else

                {
                    temp->prev->next = ahead;
                    ahead->prev = temp->prev;
                    ahead->next = temp2;
                    temp2->prev = ahead;

                    temp2->next = temp;
                    temp->prev = temp2;
                    temp->next = after;
                    after->prev = temp;

                    if (ahead->prev == tail)
                    {
                        head = ahead;
                    }

                    if (wasTail)
                    {
                        tail = ahead;
                    }

                    head->prev = tail;
                    tail->next = head;

                    temp = temp2;

                    noExchange = 0;
                }
            }

            else
            {
                temp = temp->next;
                noExchange++;
            }

        } while (noExchange < count());
    }

    void display()
    {
        Node *temp = head;
        if (head == nullptr)
        {
            cout << "\nList is empty. ";
            return;
        }
        do
        {
            cout << temp->grd.guard_id << " " << temp->grd.security_lvl << " -> ";
            temp = temp->next;
        }

        while (temp != head);
    }
};