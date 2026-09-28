#include <iostream>
#include <string>
using namespace std;

class Node

{
public:
    string data;
    Node *next;

    Node(string word)
    {
        data = word;
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

    void push(string word)
    {
        Node *newNode = new Node(word);

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

    string peek()
    {
        if (top == nullptr)
        {
            return "";
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }
};

class TextEditor
{
    string document;

    Stack undoStack;
    Stack redoStack;

public:
    void type(string word)
    {
        if (document.empty())
        {
            document = word;
        }
        else
        {
            document = document + " " + word;
        }

        undoStack.push(word);

        while (!redoStack.isEmpty())
        {
            redoStack.pop();
        }
    }

    void undo()
    {
        if (undoStack.isEmpty())
        {
            return;
        }

        string word = undoStack.peek();
        undoStack.pop();

        if (document == word)
        {
            document = "";
        }
        else
        {
            document.erase(document.length() - word.length() - 1);
        }

        redoStack.push(word);
    }

    void redo()
    {
        if (redoStack.isEmpty())
        {
            return;
        }

        string word = redoStack.peek();
        redoStack.pop();

        if (document.empty())
        {
            document = word;
        }
        else
        {
            document = document + " " + word;
        }

        undoStack.push(word);
    }

    void print()
    {
        cout << document << endl;
    }
};

int main()
{
    TextEditor editor;

    editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}