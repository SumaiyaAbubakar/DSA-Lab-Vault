#include <iostream>
using namespace std;

class QueueNode
{
public:
    int orderID;
    QueueNode *next;

    QueueNode(int id)
    {
        orderID = id;
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
        front = rear = nullptr;
    }

    void enqueue(int id)
    {
        QueueNode *newNode = new QueueNode(id);

        if (front == nullptr)
        {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue()
    {
        if (front == nullptr)
        {
            return -1;
        }

        int id = front->orderID;

        QueueNode *temp;
        temp = front;

        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        delete temp;

        return id;
    }

    void removeOrder(int id)
    {
        if (front == nullptr)
        {
            return;
        }

        if (front->orderID == id)
        {
            dequeue();
            return;
        }
        QueueNode *temp = front;

        while (temp->next != nullptr)
        {
            if (temp->next->orderID == id)
            {
                QueueNode *del = temp->next;

                temp->next = del->next;

                if (del == rear)
                {
                    rear = temp;
                }

                delete del;

                return;
            }

            temp = temp->next;
        }
    }

    void display()
    {
        QueueNode *temp = front;

        while (temp != nullptr)
        {
            cout << temp->orderID << " ";

            temp = temp->next;
        }
    }
};

class StackNode
{
public:
    int orderID;
    StackNode *next;

    StackNode(int id)
    {
        orderID = id;
        next = nullptr;
    }
};

class Stack
{
    StackNode *top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int id)
    {
        StackNode *newNode = new StackNode(id);

        if (top == nullptr)
        {
            top = newNode;
            return;
        }

        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (top == nullptr)
        {
            return -1;
        }

        int id = top->orderID;

        StackNode *del = top;
        top = top->next;
        delete del;

        return id;
    }

    void removeOrder(int id)
    {
        if (top == nullptr)
        {
            return;
        }

        if (top->orderID == id)
        {
            pop();
            return;
        }

        StackNode *temp = top;

        while (temp->next != nullptr)
        {
            if (temp->next->orderID == id)
            {
                StackNode *deleteNode = temp->next;

                temp->next = deleteNode->next;

                delete deleteNode;
                return;
            }

            temp = temp->next;
        }
    }
};

class Restaurant
{
    Queue queue;
    Stack stack;

public:
    void placeOrder(int id)
    {
        queue.enqueue(id);
        stack.push(id);
    }

    void prepareNextOrder()
    {
        int id = queue.dequeue();

        if (id != -1)
        {
            stack.removeOrder(id);
            cout << "\nPrepared order : " << id;
        }
        else
        {
            cout << "\nNo orders. ";
        }
    }

    void cancelLastOrder()
    {
        int id = stack.pop();

        if (id == -1)
        {
            cout << "\nNo order to cancel.";
            return;
        }

        queue.removeOrder(id);

        cout << "\nCancelled order: " << id;
    }

    void displayOrders()
    {
        cout << "\nQueue: ";
        queue.display();
    }
};