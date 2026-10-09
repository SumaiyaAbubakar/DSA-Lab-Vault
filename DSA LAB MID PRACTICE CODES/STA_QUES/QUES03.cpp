#include<iostream>
#include<string>
using namespace std;

struct Node 
{
string songName;
string singer;
Node* next;
Node* prev;
    Node()
    {
        next=nullptr;
        prev=nullptr;
    }
    Node(string n, string s)
    {
        songName=n;
        singer=s;
        next=nullptr;
        prev=nullptr;
    }
};

class DLL
{
    Node* head;
    Node* tail;

    public:
    DLL()
    {
        head=nullptr;
        tail=nullptr;
    }

    void AddSongHead(Node s)
    {   
        Node* newSong=new Node(s);
        if(head==nullptr)
        {
            head=newSong;
            tail=newSong;

            return;
        }

        newSong->next=head;
        head->prev=newSong;
        head=newSong;
    }

    void AddSongTail(Node s)
    {
        Node* newSong=new Node(s);

        if(head==nullptr)
        {
            head=newSong;
            tail=newSong;

            return;
        }

        tail->next=newSong;
        newSong->prev=tail;
        tail=newSong;
    }

    void AddSong(Node s, int pos)
    {

        if(pos==1)
        {
            AddSongHead(s);
            return;
        }

        Node* newSong=new Node(s);

        Node* temp=head;

        for(int i=1;i<pos;i++)
        {
            temp=temp->next;
        }

        newSong->next=temp;
        temp->prev->next=newSong;
        newSong->prev=temp->prev;
        temp->prev=newSong;
    }

    void deleteHead()
    {
        if(head==nullptr)
        {
            cout<<"\nList is empty. ";
            return;
        }

        Node* temp=head;

        if(head==tail)
        {
            head=nullptr;
            tail=nullptr;

            delete temp;

            return;
        }

        
        head=head->next;
        head->prev=nullptr;
        
        delete temp;
    }

    void deleteTail()
    {
        if(head==nullptr)
        {
            cout<<"\nList is empty. ";
            return;
        }

        Node* temp=tail;

        if(head==tail)
        {
            head=nullptr;
            tail=nullptr;
            delete temp;

            return;
        }

        

        tail=tail->prev;
        tail->next=nullptr;

        delete temp;
    }

    void deleteSong(int pos)
    {
        if(head==nullptr)
        {
            cout<<"\nList is empty. ";
            return;
        }

        if(pos==1)
        {
            deleteHead();
            return;
        }

        Node* temp;
        temp=head;

        for(int i=1;i<pos;i++)
        {
            if(temp==nullptr)
            {
                return;
            }
            temp=temp->next;
        }

        if(temp==nullptr)
        {
            return;
        }

        if(temp==tail)
        {
            deleteTail();
            return;
        }
        
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;  

        delete temp;
        
    }

    void displayForward()
    {
        Node* temp;
        temp=head;

        if(head==nullptr)
        {
            cout<<"\nList is empty.";
            return;
        }

        while(temp!=nullptr)
        {
            cout<<"\n"<<temp->singer<< " "<< temp->songName;

            temp=temp->next;
        }
    }

    void displayBackward()
    {
        if(head==nullptr)
        {
            cout<<"\nList is empty.";
            return;
        }

        Node* temp;
        temp=tail;
        
        while(temp!=nullptr)
        {
            cout<<temp->singer<< temp->songName;

            temp=temp->prev;
        }
    }

    
};