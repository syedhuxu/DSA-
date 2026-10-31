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

    // Insert at beginning
    void push_Front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head = newNode;
    }

    // Insert at end
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

    // Delete from beginning
    void pop_Front()
    {
        if (head == NULL)
        {
            cout << "LinkedList is empty" << endl;
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

    // Delete from end
    void pop_Back()
    {
        if (head == NULL)
        {
            cout << "LinkedList is empty" << endl;
            return;
        }

        // Only one node
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

    // Insert at specified position
    void insert(int val, int pos)
    {
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        if (pos == 0)
        {
            push_Front(val);
            return;
        }

        if (head == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        Node *newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        // Update tail if inserted at the end
        if (newNode->next == NULL)
        {
            tail = newNode;
        }
    }

    // Delete from specified position
    void delete_Position(int pos)
    {
        // Empty list
        if (head == NULL)
        {
            cout << "LinkedList is empty" << endl;
            return;
        }

        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Delete first node
        if (pos == 0)
        {
            pop_Front();
            return;
        }

        Node *temp = head;

        // Move to node before target
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp->next == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        // Target position does not exist
        if (temp->next == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Delete last node
        if (temp->next == tail)
        {
            pop_Back();
            return;
        }

        // Delete middle node
        Node *toDelete = temp->next;

        temp->next = toDelete->next;

        delete toDelete;
    }

    // Search for an element
    int search(int key)
    {
        Node *temp = head;
        int pos = 0;

        while (temp != NULL)
        {
            if (temp->data == key)
            {
                return pos;
            }

            temp = temp->next;
            pos++;
        }

        return -1;
    }

    // Count total nodes
    int count()
    {
        int count = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display linked list
    void print_LL()
    {
        Node *temp = head;

        if (temp == NULL)
        {
            cout << "LinkedList is empty " << endl;
            return;
        }

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
    List ll;

    cout << "Created An Empty LinkedList:" << endl;
    ll.print_LL();
    cout << endl;

    //  INSERTION
    ll.push_Front(3);
    ll.push_Front(2);
    ll.push_Front(1);

    cout << "Pushed some elements at front:" << endl;
    ll.print_LL();
    cout << endl;

    ll.push_Back(4);
    ll.push_Back(5);
    ll.push_Back(6);

    cout << "Pushed some elements at back:" << endl;
    ll.print_LL();
    cout << endl;

    ll.pop_Front();
    cout << "Deleted an element from front:" << endl;
    ll.print_LL();
    cout << endl;

    ll.pop_Back();
    cout << "Deleted an element from back:" << endl;
    ll.print_LL();
    cout << endl;

    //  INSERT AT POSITION

    cout << "Inserted 9 at position 2:" << endl;
    ll.insert(9, 2);
    ll.print_LL();
    cout << endl;

    //  DELETE AT POSITION

    cout << "Deleting element at position 2:" << endl;
    ll.delete_Position(2);

    cout << "LinkedList after deletion:" << endl;
    ll.print_LL();
    cout << endl;

    //  INVALID POSITION
    cout << "Trying to delete from invalid position 10:" << endl;
    ll.delete_Position(10);
    cout << endl;

    //  SEARCH
    int result = ll.search(4);
    cout << "Searching for element: 4" << endl;

    if (result != -1)
    {
        cout << "Element found at position: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << endl;

    result = ll.search(100);

    cout << "Searching for element: 100" << endl;

    if (result != -1)
    {
        cout << "Element found at position: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << endl;

    cout << "Total number of nodes: " << ll.count() << endl;

    return 0;
}