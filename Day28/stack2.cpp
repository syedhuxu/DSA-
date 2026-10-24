#include <iostream>
using namespace std;

struct Node
{
public:
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
        if (!newNode)
        {
            cout << "Heap overflow";
            return;
        }
        newNode->next = top;
        top = newNode;

        cout << "Pushed successfully" << endl;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Underflow" << endl;
            return -1;
        }

        Node *temp = top;
        int poppedVal = temp->data;
        top = top->next;
        delete temp;
        cout << poppedVal << " Popped from stack" << endl;
        return poppedVal;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Underflwo" << endl;
        }

        return top->data;
    }

    bool isEmpty()
    {
        return top == NULL;
    }

    void display()
    {
        if (top == NULL)
        {
            cout << "Underflow" << endl;
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
    Stack myStack;

    myStack.push(100);
    myStack.push(200);
    myStack.push(300);
    myStack.push(400);

    cout << myStack.peek() << endl;

    myStack.display();

    myStack.pop();
    myStack.pop();

    return 0;
}