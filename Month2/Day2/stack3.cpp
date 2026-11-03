#include <iostream>
using namespace std;

struct Node
{

    int data;
    Node *next;

    Node(int val)
    {
        data = val;
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

    void push(int val)
    {
        Node *newNode = new (nothrow) Node(val);
        if (newNode == nullptr)
        {
            cout << "Memory allocation failed" << endl;
            return;
        }

        if (top == NULL)
        {
            top = newNode;
            newNode->next = top;
            return;
        }
        else
        {

            Node *temp = top;
            while (temp->next != top)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = top;
            top = newNode;
        }
    }

    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        if (top->next == top)
        {
            delete top;
            top = nullptr;
            return;
        }
        Node *temp = top;
        Node *last = top;
        while (last->next != top)
        {
            last = last->next;
        }
        top = top->next;
        last->next = top;
        delete temp;
    }
};

int main()
{

    // Implementation of stack using circular linked list

    Stack s;
    s.push(10);
    s.push(20);
    return 0;
}