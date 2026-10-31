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
        arr = new int[size];
        top = -1;
        capacity = size;
    }

    void push(int val)
    {
        if (top == capacity - 1)
        {
            cout << "Stack  Overflow" << endl;
        }
        arr[++top] = val;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        int poppedVal = arr[top];
        top--;
        return poppedVal;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void peek()
    {
        if (top == -1)
        {
            cout << "Stack Underflow" << endl;
        }
        cout << arr[top] << " is the top most element" << endl;
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

    Stack s1(5);

    if (s1.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is !empty" << endl;
    }

    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.push(40);
    s1.push(50);

    s1.display();

    if (s1.isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    else
    {
        cout << "Stack is !empty" << endl;
    }

    s1.push(60);

    s1.peek();

    s1.pop();
    s1.pop();

    s1.display();

    return 0;
}