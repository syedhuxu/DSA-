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
            return;
        }

        Node *temp = top;
        int poppedVal = temp->data;
        top = top->next;
        delete temp;
        cout << poppedVal << "Popped from stack";
        return poppedVal;
    }
};

int main()
{

    return 0;
}