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

class CircularList
{
    Node *head;

public:
    CircularList()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode;
        }
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }
        if (head->next == head)
        {
            head->next = newNode;
            newNode->next = head;
            return;
        }

        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        return;
    }

    void insertAtPosition(int val, int pos)
    {
        if (pos <= 0 || head == NULL && pos > 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if (pos == 1)
        {
            insertAtBeginning(val);
            return;
        }

        Node *newNode = new Node(val);
        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
            if (temp == head)
            {
                cout << "Invalid position" << endl;
                return;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{

    CircularList cl;
    cl.insertAtBeginning(30);
    cl.insertAtBeginning(20);
    cl.insertAtBeginning(10);

    cl.display();

    cl.insertAtEnd(40);
    cl.insertAtEnd(50);
    cl.display();

    cl.insertAtPosition(25, 3);
    cl.display();

    return 0;
}