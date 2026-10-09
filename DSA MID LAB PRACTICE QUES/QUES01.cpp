#include <iostream>
using namespace std;

class Customer
{
public:
    int customer_id;
    int number_of_tickets;

    Customer() 
    {
        customer_id=0;
        number_of_tickets=0;
    }
    Customer(int id, int n)
    {
        customer_id = id;
        number_of_tickets = n;
    }
};

class Cinema
{
public:
    int available_tickets;

    Cinema()
    {
        available_tickets = 150;
    }
};

class Queue // Counter
{
    Cinema cin;
    Customer waitingArea[50];

    int front;
    int rear;
    int count;

public:
    Queue()
    {
        front = 0;
        count = 0;
        rear = -1;
    }

    bool isEmpty()
    {
        return count == 0;
    }

    bool isFull()
    {
        return count == 50;
    }
    void enqueue(Customer c)
    {
        if (isFull())
        {
            return;
        }
        rear = (rear + 1) % 50;
        waitingArea[rear] = c;

        count++;
    }

    Customer dequeue()
    {
        if (isEmpty())
        {
            return Customer();
        }

        Customer temp = waitingArea[front];

        if (temp.number_of_tickets <= cin.available_tickets)
        {
            cin.available_tickets = cin.available_tickets - temp.number_of_tickets;
        }

        front = (front + 1) % 50;
        count--;

        return temp;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "\nWaiting area is empty. ";
            return;
        }
        cout << "\nCustomer currently at front : " << waitingArea[front].customer_id << " " << waitingArea[front].number_of_tickets;
        cout << "\nCustomer currently at rear : " << waitingArea[rear].customer_id << " " << waitingArea[rear].number_of_tickets;
        cout << "\nCustomers waiting... : " << count;
    }
};