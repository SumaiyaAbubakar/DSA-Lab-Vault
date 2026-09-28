#include <iostream>
using namespace std;

class Node
{
public:
    char ch;
    Node *next;

    Node(char c)
    {
        ch = c;
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

    void push(char c)
    {
        Node *newNode = new Node(c);

        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == nullptr)
        {
            return;
        }

        Node *temp = top;
        top = top->next;
        delete temp;
    }

    int peek()
    {
        if (top == nullptr)
        {
            return -1;
        }

        return top->ch;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    int size()
    {
        int count = 0;

        Node *temp = top;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

class MyQueue
{
    Stack incomingStack;
    Stack outgoingStack;

public:
    void enqueue(char c)
    {
        incomingStack.push(c);
    }

    char dequeue()
    {
        if (outgoingStack.isEmpty())
        {
            while (!incomingStack.isEmpty())
            {
                char temp = incomingStack.peek();
                incomingStack.pop();
                outgoingStack.push(temp);
            }
        }

        char temp = outgoingStack.peek();
        outgoingStack.pop();

        return temp;
    }
};

int main()
{
    MyQueue q;

    q.enqueue('A');
    q.enqueue('B');

    cout << q.dequeue() << endl;

    q.enqueue('C');

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    return 0;
}