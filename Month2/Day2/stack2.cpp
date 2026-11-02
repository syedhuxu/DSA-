#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{

    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    void push(int val)
    {
        Node *newNode = new Node(val);
        if (top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        delete temp;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    // iMPLEMENTATION OF STACK USING SINGLY LINKED LIST

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    return 0;
}