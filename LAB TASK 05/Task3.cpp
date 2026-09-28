#include <iostream>
using namespace std;

class Node
{
public:
    int job;
    Node *next;

    Node(int j)
    {
        job = j;
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

    void push(int j)
    {
        Node *newNode = new Node(j);

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

        return top->job;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class Queue
{
    Node *front;
    Node *rear;

public:
    Queue()
    {
        front = rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void enqueue(int j)
    {
        Node *newNode = new Node(j);

        if (front == nullptr)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty.";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;
    }

    int peek()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty. ";
            return -1;
        }

        return front->job;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nQueue is empty. ";
            return;
        }

        Node *temp = front;
        while (temp != nullptr)
        {
            cout << temp->job << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    int countsize()
    {
        int count = 0;

        Node *temp = front;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

void reverseFirstK(Queue &q, int k)
{
    Stack st;
    for (int i = 0; i < k; i++)
    {
        int temp1 = q.peek();
        q.dequeue();
        st.push(temp1);
    }

    for (int i = 0; i < k; i++)
    {
        int temp2 = st.peek();
        st.pop();
        q.enqueue(temp2);
    }

    int remaining = q.countsize() - k;

    for (int i = 0; i < remaining; i++)
    {
        int temp3 = q.peek();
        q.dequeue();
        q.enqueue(temp3);
    }
}

int main()
{
    Queue q;

    for(int i = 1; i <= 7; i++)
    {
        q.enqueue(i);
    }

    cout << "Original Queue: ";
    q.display();

    int k = 3;

    reverseFirstK(q, k);

    cout << "After reversing first " << k << " elements: ";
    q.display();

    return 0;
}