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

    void peek()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Top element: " << top->data << endl;
    }

    bool isEmpty()
    {
        return top == nullptr;
    }

    void display()
    {
        if (top == nullptr)
        {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != top);
    }
};

int main()
{

    // Implementation of stack using circular linked list

    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.peek();
    s.display();
    cout << endl;

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    s.pop();

    s.display();
    return 0;
}