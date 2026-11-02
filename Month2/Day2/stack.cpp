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
};

int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    s.pop();
    return 0;
}