#include <iostream>
using namespace std;

class Node
{
public:
    string website;
    Node *next;

    Node(string web)
    {
        website = web;
        next = nullptr;
    }
};

class Stack
{
    Node *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(string web)
    {
        Node *newNode = new Node(web);

        newNode->next = top;
        top = newNode;
    }

    string pop()
    {
        if (top == nullptr)
        {
            return " ";
        }

        string website = top->website;

        Node *del = top;

        top = top->next;

        delete del;

        return website;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class Browser
{
    Stack back;
    Stack Forward;
    string current;

public:
    Browser()
    {
        current = " ";
    }

    void visit(string website)
    {
        if (current != " ")
        {
            back.push(current);
        }

        current = website;

        while (!Forward.isEmpty())
        {
            Forward.pop();
        }
    }

    void back()
    {
        if (back.isEmpty())
        {
            return;
        }

        Forward.push(current);
        current = back.pop();
    }

    void Forward()
    {
        if(Forward.isEmpty())
        {
            return;
        }

        back.push(current);
        current=Forward.pop();
    }

    void current()
    {
        cout<<"\n Current page : "<<current;
    }
};