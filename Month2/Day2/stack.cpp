#include <iostream>
using namespace std;
#define MAX 10

class Stack
{
    int arr[MAX];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    void push(int x)
    {
        if (top >= MAX - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = x;
            cout << x << " pushed into stack" << endl;
        }
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
        }
        else
        {
            cout << arr[top--] << " popped from stack" << endl;
        }
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    void peek()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Top element is: " << arr[top] << endl;
        }
    }

    void display()
    {
        if (top < 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            cout << "Stack elements are: ";
            for (int i = top; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    s.pop();
    s.display();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    s.peek();

    s.display();
    return 0;
}