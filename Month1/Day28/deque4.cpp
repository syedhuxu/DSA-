#include <iostream>
using namespace std;

// IMPLEMENTATION OF DEQUE USING CIRCULAR ARRAY:

class CircularDeque
{
    int *arr;
    int front, rear, capacity;

public:
    // Constructor initialize karne k liye
    CircularDeque(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        return ((front == 0 && rear == capacity - 1) || front == rear + 1);
    }

    bool isEmpty()
    {
        return (front == -1);
    }

    // Front se insert karna
    void push_front(int key)
    {
        if (isFull())
        {
            cout << "Overflow! Deque full hai." << endl;
            return;
        }
        if (front == -1)
        { // Agar array  khali hova
            front = 0;
            rear = 0;
        }
        else if (front == 0)
        { //  first se last pe shift
            front = capacity - 1;
        }
        else
        { // Normal case
            front = front - 1;
        }
        arr[front] = key;
    }

    // Back (rear) se insert karna
    void push_back(int key)
    {
        if (isFull())
        {
            cout << "Overflow! Deque full hai." << endl;
            return;
        }
        if (front == -1)
        { // Agar array bilkul khali hai
            front = 0;
            rear = 0;
        }
        else if (rear == capacity - 1)
        { // Circular property: last se first pe shift
            rear = 0;
        }
        else
        { // Normal case
            rear = rear + 1;
        }
        arr[rear] = key;
    }

    // Front se delete karna
    void pop_front()
    {
        if (isEmpty())
        {
            cout << "Underflow! Deque khali hai." << endl;
            return;
        }
        if (front == rear)
        { // Sirf ek element bacha tha
            front = -1;
            rear = -1;
        }
        else if (front == capacity - 1)
        { // Circular pop
            front = 0;
        }
        else
        { // Normal case
            front = front + 1;
        }
    }

    // Back (rear) se delete karna
    void pop_back()
    {
        if (isEmpty())
        {
            cout << "Underflow! Deque khali hai." << endl;
            return;
        }
        if (front == rear)
        { // Sirf ek element bacha tha
            front = -1;
            rear = -1;
        }
        else if (rear == 0)
        { // Circular pop
            rear = capacity - 1;
        }
        else
        { // Normal case
            rear = rear - 1;
        }
    }

    // Deque elements ko print karna
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque empty hai." << endl;
            return;
        }
        cout << "Current Deque: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % capacity; // Circular increment
        }
        cout << endl;
    }
};

int main()
{
    CircularDeque dq(5);

    // Insertion
    dq.push_back(10); // Deque: 10
    dq.push_back(20); // Deque: 10, 20
    dq.push_front(5); // Deque: 5, 10, 20
    dq.push_front(2); // Deque: 2, 5, 10, 20

    dq.display();

    //  Deletion
    dq.pop_front(); // 2 remove hoga
    dq.pop_back();  // 20 remove hoga

    dq.display();

    // Circular  test
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);

    dq.display(); // Output: 5 10 30 40 50

    return 0;
}