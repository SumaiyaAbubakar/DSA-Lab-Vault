#include <iostream>
#include <string>
using namespace std;

class Page
{
public:
    int page_ID;
    string page_Title;
    int visitCount;
    int lastUsed;

    Page()
    {
        page_ID = 0;
        page_Title = "";
        visitCount = 0;
        lastUsed = 0;
    }

    Page(int id, string t, int n, int l)
    {
        page_ID = id;
        page_Title = t;
        visitCount = n;
        lastUsed = l;
    }
};

class Node
{
public:
    Page pg;
    Node *next;
    Node *prev;

    Node(Page p)
    {
        pg = p;
        next = nullptr;
        prev = nullptr;
    }
};

class DLL // browser
{
    Node *head;
    Node *tail;
    Node *current;
    int capacity;
    int time;
    int size;

public:
    DLL(int limit)
    {

        head = nullptr;
        tail = nullptr;
        current = nullptr;
        capacity = limit;
        time = 0;
        size = 0;
    }

    void visitPage(Page p)
    {
        time++;

        Node *temp = head;

        while (temp != nullptr)
        {

            if (temp->pg.page_ID == p.page_ID)
            {
                temp->pg.visitCount++;
                current = temp;
                temp->pg.lastUsed = time;
                return;
            }

            temp = temp->next;
        }

        if (size == capacity)
        {
            Node *oldest = findOldest();
            deleteNode(oldest);
        }

        Node *newNode = new Node(p);

        if (head == nullptr)
        {

            head = newNode;
            tail = newNode;
            current = newNode;
        }

        else
        {
            tail->next = newNode;
            newNode->prev = tail;

            tail = newNode;

            current = newNode;
        }

        newNode->pg.lastUsed = time;
        size++;
    }

    Node *findOldest()
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        Node *oldest = head;
        Node *temp = head;

        while (temp != nullptr)
        {
            if (temp->pg.lastUsed < oldest->pg.lastUsed)
            {
                oldest = temp;
            }
            temp = temp->next;
        }

        return oldest;
    }

    void deleteHead()
    {
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }

        if (head == tail)
        {
            head = tail = nullptr;
        }

        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteTail()
    {
        Node *temp = tail;

        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }

        if (head == tail)
        {
            head = tail = nullptr;
        }

        else
        {

            tail = tail->prev;
            tail->next = nullptr;
        }

        delete temp;
    }

    void deleteNode(Node *node)
    {
        size--;

        if (head == nullptr)
        {
            cout << "\nList is empty.";
            return;
        }

        if (node == current)
        {
            current = nullptr;
        }

        if (node == head)
        {
            deleteHead();
            return;
        }

        if (node == tail)
        {
            deleteTail();
            return;
        }

        node->prev->next = node->next;
        node->next->prev = node->prev;

        delete node;
    }

    void backward()
    {
        if (current != nullptr && current->prev != nullptr)
        {
            current = current->prev;

            time++;
            current->pg.lastUsed = time;
            current->pg.visitCount++;
        }
    }

    void forward()
    {
        if (current != nullptr && current->next != nullptr)
        {
            current = current->next;

            time++;
            current->pg.lastUsed = time;
            current->pg.visitCount++;
        }
    }

    void displayHistory()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->pg.page_ID << " "
                 << temp->pg.page_Title << " "
                 << temp->pg.visitCount << " "
                 << temp->pg.lastUsed << endl;

            temp = temp->next;
        }
    }

    void displayReverse()
    {
        Node *temp = tail;

        while (temp != nullptr)
        {
            cout << temp->pg.page_ID << " "
                 << temp->pg.page_Title << " "
                 << temp->pg.visitCount << " "
                 << temp->pg.lastUsed << endl;

            temp = temp->prev;
        }
    }
};