#include <iostream>
using namespace std;

// IMPLEMENTATION OF DEQUE USING Doubly Linked List:

struct Node
{
    int data;
    Node *prev;
    Node *next;

    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class DLLDeque
{
    Node *front;
    Node *rear;

public:
    // Constructor
    DLLDeque()
    {
        front = nullptr;
        rear = nullptr;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    void insertFront(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            newNode->next = front;

            front->prev = newNode;

            front = newNode;
        }
        cout << val << "Insertion at front successfull\n";
    }

    void insertRear(int val)
    {
        Node *newNode = new Node(val);

        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {

            rear->next = newNode;

            newNode->prev = rear;

            rear = newNode;
        }
        cout << val << "Insertion at rear successufll.\n";
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Deque empty.\n";
            return;
        }

        Node *temp = front;
        cout << "Current Deque: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    DLLDeque dq;

    dq.insertFront(10); // Deque: [10]
    dq.insertRear(20);  // Deque: [10, 20]
    dq.insertFront(5);  // Deque: [5, 10, 20]

    dq.display();

    return 0;
}