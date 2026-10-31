#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class sLL
{
    Node *head;

public:
    sLL()
    {
        head = NULL;
    }

    void insertAtStarting(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        if (head == NULL)
        {
            insertAtStarting(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // If inserting at the very beginning
        if (pos == 1 || head == NULL)
        {
            insertAtStarting(val);
            return;
        }

        Node *temp = head;
        // Move to the (pos - 1)th node
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Position out of bounds!" << endl;
                return;
            }
            temp = temp->next;
        }

        if (temp == NULL)
        {
            cout << "Position out of bounds!" << endl;
            return;
        }

        Node *newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List" << endl;
            return;
        }

        Node *temp = head;
        while (temp != NULL)
        { // Fixed: safely processes every single node
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    sLL list;

    list.insertAtStarting(10);
    list.insertAtStarting(10);
    list.insertAtStarting(10);

    list.insertAtEnd(15);
    list.insertAtPos(20, 2);

    list.display();

    return 0;
}
