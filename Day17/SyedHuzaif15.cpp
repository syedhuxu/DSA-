#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class List
{
    Node *head;
    Node *tail;

public:
    // Constructor
    List()
    {
        head = tail = NULL;
    }

    // Insert at beginning
    void push_Front(int val)
    {
        Node *newNode = new Node(val);

        // Empty list
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void push_Back(int val)
    {
        Node *newNode = new Node(val);

        // Empty list
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    // Insert at specified position
    // Positions are 0-based
    void insert(int val, int pos)
    {
        // Negative position
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Insert at beginning
        if (pos == 0)
        {
            push_Front(val);
            return;
        }

        // Find the node at position pos - 1
        Node *temp = head;

        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        // Position is invalid
        if (temp == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Insert at the end
        if (temp == tail)
        {
            push_Back(val);
            return;
        }

        Node *newNode = new Node(val);

        // Connect new node in both directions
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // Display in forward direction
    void print_Forward()
    {
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
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

    // Display in backward direction
    void print_Backward()
    {
        if (tail == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        Node *temp = tail;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->prev;
        }

        cout << endl;
    }

    // Delete from beginning
    void pop_Front()
    {
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Only one node
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;

        head = head->next;
        head->prev = NULL;

        temp->next = NULL;
        delete temp;
    }

    // Delete from end
    void pop_Back()
    {
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Only one node
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node *temp = tail;

        tail = tail->prev;
        tail->next = NULL;

        temp->prev = NULL;
        delete temp;
    }

    // Delete from specified position
    // Positions are 0-based
    void delete_Position(int pos)
    {
        // Empty list
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Invalid negative position
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

        // Move to required position
        for (int i = 0; i < pos; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        // Position does not exist
        if (temp == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Delete last node
        if (temp == tail)
        {
            pop_Back();
            return;
        }

        // Connect previous node to next node
        temp->prev->next = temp->next;

        // Connect next node to previous node
        temp->next->prev = temp->prev;

        delete temp;
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

    // Count total number of nodes
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
};

int main()
{
    List dll;

    // EMPTY DOUBLY LINKED LIST

    cout << "Created an Empty Doubly LinkedList:" << endl;
    dll.print_Forward();
    cout << endl;

    // INSERTION

    dll.push_Back(10);
    dll.push_Back(20);
    dll.push_Back(30);

    cout << "Created Doubly LinkedList by inserting elements:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Insert at beginning
    dll.push_Front(5);

    cout << "After inserting 5 at beginning:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Insert at specified position
    dll.insert(15, 2);

    cout << "After inserting 15 at position 2:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Insert at end
    dll.push_Back(40);

    cout << "After inserting 40 at end:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Invalid insertion
    cout << "Trying to insert 100 at invalid position 20:" << endl;
    dll.insert(100, 20);

    cout << endl;

    // DELETION

    // Delete from beginning
    dll.pop_Front();

    cout << "After deleting from beginning:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Delete from specified position
    dll.delete_Position(2);

    cout << "After deleting node from position 2:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Delete from end
    dll.pop_Back();

    cout << "After deleting from end:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Invalid deletion
    cout << "Trying to delete from invalid position 20:" << endl;
    dll.delete_Position(20);

    cout << endl;

    // SEARCH

    int result = dll.search(20);

    cout << "Searching for element 20:" << endl;

    if (result != -1)
    {
        cout << "Element found at position: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << endl;

    // Search for element that doesn't exist
    result = dll.search(100);

    cout << "Searching for element 100:" << endl;

    if (result != -1)
    {
        cout << "Element found at position: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << endl;

    // COUNT

    cout << "Total number of nodes: " << dll.count() << endl;

    return 0;
}