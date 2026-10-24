#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int top;
    int capacity;

public:
    Stack(int size)
    {
        capacity = size;
        top = -1;
        arr = new int[size];
    }

    void push(int val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack Overflow..." << endl;
            ;
            return;
        }
        arr[++top] = val;
        cout << val << " Insertion successfull" << endl;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
            ;
            return -1;
        }

        int poppedVal = arr[top];
        top--;
        cout << poppedVal << " Popped from stack" << endl;
        return poppedVal;
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow " << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty()
    {

        return top == -1;
    }

    void display()
    {
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack myStack(5);

    if (myStack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is !empty" << endl;
    }

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);
    myStack.push(50);

    if (myStack.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is !empty" << endl;
    }

    myStack.display();

    myStack.push(60);

    cout << "Sabse upar hai: " << myStack.peek() << "\n";

    myStack.pop();
    myStack.pop();

    myStack.display();

    return 0;
}