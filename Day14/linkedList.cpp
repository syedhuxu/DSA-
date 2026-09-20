#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class List
{
    Node *head;
    Node *tail;

public:
    List()
    {
        head = tail = NULL;
    }

    void push_Front(int val)
    {
        // Node newNode(val);  Static implementation
        Node *newNode = new Node(val); // Dynamic object

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }
        else
        {
            newNode->next = head; // (*newNode).next= head
            head = newNode;
        }
    }

    void push_Back(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_Front()
    {
        if (head == NULL)
        {
            cout << "LinkedList is empty";
            return;
        }
        Node *temp = head;
        head = head->next;

        if (head == NULL)
        {
            tail = NULL;
        }

        temp->next = NULL;
        delete temp;
    }

    void pop_Back()
    {
        if (head == NULL)
        {
            cout << "LinkedList is empty";
            return;
        }

        if (head == tail)
        {
            delete head;
            head = NULL;
            tail = NULL;
            return;
        }

        Node *temp = head;
        while (temp->next != tail)
        {
            temp = temp->next;
        }

        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print_LL()

    {
        Node *temp = head;
        while (temp != NULL)

        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << " " << endl;
    }
};
int main()
{
    List ll;
    ll.push_Front(3);
    ll.push_Front(2);
    ll.push_Front(1);
    cout << "Pushed some elements at front" << endl;
    ll.print_LL();

    ll.push_Back(4);
    ll.push_Back(5);
    ll.push_Back(6);
    cout << "Pushed some elements at back" << endl;
    ll.print_LL();

    ll.pop_Front();
    cout << "poped an elements from front" << endl;
    ll.print_LL();

    ll.pop_Back();
    cout << "poped an elements from back" << endl;
    ll.print_LL();

    cout << "Final LinkedList after operations" << endl;
    ll.print_LL();

    return 0;
}