#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor: naya node banta hai aur starting me links NULL hote hain
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
    // Starting me list empty hai
    List()
    {
        head = tail = NULL;
    }

    // Node ko beginning me add karna
    void push_Front(int val)
    {
        Node *newNode = new Node(val);

        // Agar list empty hai to ye first node hoga
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        // Naye node ko purane head se connect karo
        newNode->next = head;
        head->prev = newNode;

        // Ab new node hi head hai
        head = newNode;
    }

    // Node ko end me add karna
    void push_Back(int val)
    {
        Node *newNode = new Node(val);

        // Empty list me new node head aur tail dono hoga
        if (head == NULL)
        {
            head = tail = newNode;
            return;
        }

        // Naye node ka previous tail hoga
        newNode->prev = tail;
        tail->next = newNode;

        // Ab new node hi tail hai
        tail = newNode;
    }

    // Given position par node insert karna
    // Position 0-based hai
    void insert(int val, int pos)
    {
        // Negative position valid nahi hai
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Position 0 means beginning
        if (pos == 0)
        {
            push_Front(val);
            return;
        }

        Node *temp = head;

        // Insertion ke liye pos - 1 wali position tak jana hai
        for (int i = 0; i < pos - 1; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        // Agar required position exist hi nahi karti
        if (temp == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Agar tail ke baad insert karna hai to push_Back use karo
        if (temp == tail)
        {
            push_Back(val);
            return;
        }

        Node *newNode = new Node(val);

        // New node ko dono directions me connect karna hai
        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    // List ko head se tail tak display karna
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

    // List ko tail se head tak display karna
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

    // Beginning se node delete karna
    void pop_Front()
    {
        // Empty list se delete nahi kar sakte
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Agar sirf ek node hai
        if (head == tail)
        {
            delete head;
            head = tail = NULL;
            return;
        }

        Node *temp = head;

        // Head ko next node par shift karo
        head = head->next;

        // Naye head ka previous NULL hoga
        head->prev = NULL;

        // Purane node ko delete karo
        temp->next = NULL;
        delete temp;
    }

    // End se node delete karna
    void pop_Back()
    {
        // Empty list check
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Agar sirf ek hi node hai
        if (head == tail)
        {
            delete tail;
            head = tail = NULL;
            return;
        }

        Node *temp = tail;

        // Tail ko previous node par shift karo
        tail = tail->prev;

        // Naye tail ka next NULL hoga
        tail->next = NULL;

        // Purane tail ko delete karo
        temp->prev = NULL;
        delete temp;
    }

    // Given position ka node delete karna
    // Position 0-based hai
    void delete_Position(int pos)
    {
        // Empty list se deletion possible nahi hai
        if (head == NULL)
        {
            cout << "Doubly LinkedList is empty" << endl;
            return;
        }

        // Negative position valid nahi hai
        if (pos < 0)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Position 0 par first node delete hoga
        if (pos == 0)
        {
            pop_Front();
            return;
        }

        Node *temp = head;

        // Required position tak move karo
        for (int i = 0; i < pos; i++)
        {
            if (temp == NULL)
            {
                cout << "Invalid Position" << endl;
                return;
            }

            temp = temp->next;
        }

        // Agar position list me exist nahi karti
        if (temp == NULL)
        {
            cout << "Invalid Position" << endl;
            return;
        }

        // Agar last node delete karna hai
        if (temp == tail)
        {
            pop_Back();
            return;
        }

        // Previous aur next node ko aapas me connect karo
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        // Ab current node ko delete kar sakte hain
        delete temp;
    }

    // Element ko search karke uski first position return karna
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

        // Element nahi mila
        return -1;
    }

    // Total nodes count karna
    int count()
    {
        int total = 0;
        Node *temp = head;

        while (temp != NULL)
        {
            total++;
            temp = temp->next;
        }

        return total;
    }
};

int main()
{
    List dll;

    //  EMPTY LIST

    cout << "Created an Empty Doubly LinkedList:" << endl;
    dll.print_Forward();
    cout << "Total nodes in empty list: " << dll.count() << endl;
    cout << endl;

    //  INSERTION

    // Empty list me elements add karna
    dll.push_Back(10);
    dll.push_Back(20);
    dll.push_Back(30);

    cout << "Created Doubly LinkedList by inserting elements:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Beginning me element insert karna
    dll.push_Front(5);

    cout << "After inserting 5 at beginning:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Specified position par element insert karna
    dll.insert(15, 2);

    cout << "After inserting 15 at position 2:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // End me element insert karna
    dll.push_Back(40);

    cout << "After inserting 40 at end:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Invalid position par insertion try karna
    cout << "Trying to insert 100 at invalid position 20:" << endl;
    dll.insert(100, 20);

    cout << endl;

    //  DELETION

    // Beginning se delete karna
    dll.pop_Front();

    cout << "After deleting from beginning:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Specified position se delete karna
    dll.delete_Position(2);

    cout << "After deleting node from position 2:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // End se delete karna
    dll.pop_Back();

    cout << "After deleting from end:" << endl;

    cout << "Forward Direction: ";
    dll.print_Forward();

    cout << "Backward Direction: ";
    dll.print_Backward();

    cout << endl;

    // Invalid position se delete try karna
    cout << "Trying to delete from invalid position 20:" << endl;
    dll.delete_Position(20);

    cout << endl;

    //  SEARCH

    // List me present element search karna
    int result = dll.search(15);

    cout << "Searching for element 15:" << endl;

    if (result != -1)
    {
        cout << "Element found at position: " << result << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    cout << endl;

    // List me present nahi hone wala element search karna
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

    //  COUNT

    cout << "Total number of nodes in non-empty list: ";
    cout << dll.count() << endl;

    cout << endl;

    //  ONLY NODE CASE

    // List ko sirf ek node tak le aate hain
    while (dll.count() > 1)
    {
        dll.pop_Front();
    }

    cout << "List before deleting the only remaining node:" << endl;
    dll.print_Forward();

    // Only node delete karna
    dll.pop_Front();

    cout << "List after deleting the only node:" << endl;
    dll.print_Forward();

    cout << "Total nodes: " << dll.count() << endl;

    cout << endl;

    //  EMPTY LIST DELETION

    cout << "Trying to delete from an empty list:" << endl;
    dll.pop_Front();

    return 0;
}
