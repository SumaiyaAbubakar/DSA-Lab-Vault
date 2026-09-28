#include<iostream>
using namespace std;

class Queue
{
    int gateCapacity[6];
    int front;
    int rear;
    int count;

    public:
    Queue()
    {
        front=0;
        rear=-1;
        count=0;
    }

    bool isEmpty()
    {
        return count==0;
    }

    bool isFull()
    {
        return count==6;
    }

    void enqueue(int p_ID)
    {
        if(isFull())
        {
            cout<<"\nQueue overflow.";
            return;
        }

        rear=(rear+1)%6;
        gateCapacity[rear]=p_ID;

        count++;
    }

    int dequeue()

    {
        if(isEmpty())
        {
            cout<<"\nQueue underflow. ";
            return -1;
        }

        int temp=gateCapacity[front];

        front=(front+1)%6;
        
        count--;

        return temp;
    }

    void peek()
    {
        if(isEmpty())
        {
            cout<<"\nQueue is empty. ";
            return;
        }

        cout<<"\nFront passenger ID : "<<gateCapacity[front];
    }

    void display()
    {
        if(isEmpty())
        {
            cout<<"\nQueue is empty. ";
            return;
        }

        int index = front;

        for(int i = 0; i < count; i++)
        {
            cout << gateCapacity[index] << " ";
            index = (index + 1) % 6;
        }

        cout<<endl;
    }
};

int main()
{
    Queue q;
    for(int i = 101; i <= 106; i++)
    {
        q.enqueue(i);
    }

    for(int i = 0; i < 3; i++)
    {
        cout << "Boarded: " << q.dequeue() << endl;
    }

    for(int i = 107; i <= 109; i++)
    {
        q.enqueue(i);
    }

    for(int i = 0; i < 2; i++)
    {
        cout << "Boarded: " << q.dequeue() << endl;
    }

    q.enqueue(110);

    cout << "Boarded: " << q.dequeue() << endl;

    for(int i = 111; i <= 112; i++)
    {
        q.enqueue(i);
    }

    cout << "\nFinal passengers: ";
    q.display();

    return 0;
}