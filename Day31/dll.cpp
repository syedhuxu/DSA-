#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class Dll
{
    Node *head;

public:
    Dll()
    {
        head = NULL;
    }

    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void deleteAtBeginning()
    {
        if (head == NULL)
        {
            cout << "Linked list is empty..." << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete temp;
    }

    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteAtEnd()
    {
        if (head == NULL)
        {
            cout << "Empty Linked List..." << endl;
            return;
        }
        if (head->next == NULL)
        {
            delete head;
            head = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void insertAtPos(int val, int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position entered..." << endl;
            return;
        }
        Node *newNode = new Node(val);
        if (pos == 1)
        {
            if (head != NULL)
            {
                head->next = newNode;
                newNode->prev = head;
                head = newNode;
            }
        }

        if (head == NULL)
        {
            cout << "Out of Range";
            return;
        }

        Node *temp = head;
        for (int i = 1; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Out of Range";
                delete temp;
                return;
            }
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != NULL)
        {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteAtPos(int pos)
    {
        if (pos <= 0)
        {
            cout << "Invalid position entered..." << endl;
            return;
        }

        if (head == NULL)
        {
            cout << "linked list is empty..";
            return;
        }

        if (pos == 1)
        {
            deleteAtBeginning();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                cout << "Position out of range";
                return;
            }
        }
        if (temp->prev != NULL)
        {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "DLL is empty..." << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Dll l1;
    l1.insertAtBeginning(40);
    l1.insertAtBeginning(30);
    l1.insertAtBeginning(20);
    l1.insertAtBeginning(10);
    l1.insertAtEnd(99);
    // l1.display();

    l1.insertAtPos(50, 3);

    l1.display();
    // l1.deleteAtEnd();
    // l1.display();

    l1.deleteAtPos(10);
    // l1.display();
    return 0;
}
