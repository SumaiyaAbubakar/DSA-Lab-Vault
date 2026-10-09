#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int token;
    string name;
    string problem;

    Student()
    {
        token=0;
        name=" ";
        problem=" ";
    }
    Student(int t, string n, string p)
    {
        token = t;
        name = n;
        problem = p;
    }
};

class Queue
{
    Student st[100];
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
        return count==0;
    }

    bool isFull()
    {
        return count==100;
    }
    void addStudent(Student s)
    {
        if(isFull())
        {
            return;
        }

        rear=(rear+1)%100;
        st[rear]=s;

        count++;
    }

    Student serveStudent()
    {
        if(isEmpty())
        {
            return Student();
        }

        Student del=st[front];
        front=(front+1)%100;
        count--;

        return del;

    }

    void nextStudent()
    {
        if(isEmpty())
        {
            return;
        }
        cout<<"\n"<<st[front].name<< " "<<st[front].problem << " " << st[front].token<< " ";
    }

    void displayWaitingStudents()
    {
        if(isEmpty())
        {
            cout<<"\nNo students waiting. All served. ";
            return;
        }

        cout<<"\nWaiting students : "<<count;
    }
};