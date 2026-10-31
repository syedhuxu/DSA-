#include <iostream>
using namespace std;

// IMPLEMENTATION OF DEQUE USING CIRCULAR ARRAY:

class CircularDeque
{
    int *arr;
    int front, rear;
    int capacity, size;

public:
    // Constructor
    CircularDeque(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isFull()
    {
        return size == capacity;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void insertFront(int key)
    {
        if (isFull())
        {
            cout << "Overflow \n";
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = key;
        size++;
        cout << key << " Insertion at front successfull.\n";
    }

    void insertRear(int key)
    {
        if (isFull())
        {
            cout << "Overflow\n";
            return;
        }

        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = key;
        size++;
        cout << key << " Insertion at rear successfull\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque empty.\n";
            return;
        }

        cout << "Current Deque: ";
        int i = front;
        for (int count = 0; count < size; count++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
        }
        cout << "\n";
    }
};

int main()
{
    CircularDeque dq(5);

    // Insertion
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);

    dq.display();

    return 0;
}