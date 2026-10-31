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
        display();
        return;
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
        display();
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
        display();
        return;
    }

    void deleteFirst()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        Node *toDelete = head;
        head = head->next;
        temp->next = head;
        delete toDelete;
        cout << "Circular Linked List after deleting the first node: " << endl;

        display();

        return;
    }

    void deleteEnd()
    {
        if (head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next->next != head)
        {
            temp = temp->next;
        }
        Node *toDelete = temp->next;
        temp->next = head;
        delete toDelete;
        cout << "Circular Linked List after deleting the last node: " << endl;

        display();

        return;
    }

    void deleteAtPosition(int pos)
    {
        if (pos <= 0 || head == NULL)
        {
            cout << "Invalid position" << endl;
            return;
        }
        if (pos == 1)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            Node *toDelete = head;
            head = head->next;
            temp->next = head;
            delete toDelete;
            return;
        }
        Node *temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head)
        {
            temp = temp->next;
            i++;
        }
        if (i != pos - 1 || temp->next == head)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node *toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << "Circular Linked List after deleting at position 2: " << endl;

        display();

        return;
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

    cout << "Circular Linked List after inserting at the beginning: " << endl;

    cl.insertAtEnd(40);
    cl.insertAtEnd(50);
    cout << "Circular Linked List after inserting at the end: " << endl;

    cl.insertAtPosition(25, 3);
    cout << "Circular Linked List after inserting at position 3: " << endl;
    cl.display();

    cl.deleteFirst();

    cl.deleteEnd();

    cl.deleteAtPosition(2);

    return 0;
}