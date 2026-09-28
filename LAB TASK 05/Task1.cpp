#include<iostream>
using namespace std;

class Stack
{
    int arr[6];
    int top;

    public:
    Stack()
    {
        top=-1;
    }

    void push(int value)
    {
        if(top==5)
        {
            cout<<"Stack overflow.";
            return;
        }

        arr[++top]=value;
        
    }

    void pop()
    {
        if(top==-1)
        {
            cout<<"Stack underflow.";
            return;
        }

        top--;
    }

    void peek()
    {
        if(top==-1)
        {
            cout<<"Stack is empty ."<<endl;
        }

        cout<<"Current top : "<< arr[top]<<endl;
    }

    bool isempty()
    {
        return top==-1;
    }

    void display()
    {
        for(int i=top;i>=0;i--)
        {
            cout<<arr[i]<<" ";

        }

        cout<<endl;
    }
};

int main()
{
    Stack st;

    st.push(12);
    st.push(25);
    st.push(17);
    st.push(31);
    st.push(44);
    st.push(19);
    
    st.pop();
    st.peek();

    st.pop();
    st.peek();

    st.pop();
    st.peek();

    st.push(52);
    st.peek();

    st.pop();
    st.peek();

    st.pop();
    st.peek();

    st.display();

    return 0;
}