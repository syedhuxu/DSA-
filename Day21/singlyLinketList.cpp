
#include <iostream>
using namespace std;

class SinglyLinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;

        Node(int value)
        {
            data = value;
            next = nullptr;
        }
    };

    Node *head;

public:
    // Initially list is empty
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Free all remaining nodes when the object is destroyed
    ~SinglyLinkedList()
    {
        Node *current = head;

        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // 1. Insert at beginning
    bool insertAtBeginning(int value)
    {
        Node *newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        return true;
    }

    // 2. Insert at end
    bool insertAtEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == nullptr)
        {
            head = newNode;
            return true;
        }

        Node *current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = newNode;
        return true;
    }

    // 3. Insert at a 1-based position
    bool insertAtPosition(int value, int position)
    {
        if (position < 1)
        {
            return false;
        }

        if (position == 1)
        {
            return insertAtBeginning(value);
        }

        Node *current = head;

        for (int i = 1;
             i < position - 1 && current != nullptr;
             i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            return false;
        }

        Node *newNode = new Node(value);

        newNode->next = current->next;
        current->next = newNode;

        return true;
    }

    // 4. Delete at beginning
    bool deleteAtBeginning()
    {
        if (head == nullptr)
        {
            return false;
        }

        Node *nodeToDelete = head;
        head = head->next;

        delete nodeToDelete;
        return true;
    }

    // 5. Delete at end
    bool deleteAtEnd()
    {
        if (head == nullptr)
        {
            return false;
        }

        // Only one node
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return true;
        }

        Node *current = head;

        while (current->next->next != nullptr)
        {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;

        return true;
    }

    // 6. Delete at a 1-based position
    bool deleteAtPosition(int position)
    {
        if (position < 1 || head == nullptr)
        {
            return false;
        }

        if (position == 1)
        {
            return deleteAtBeginning();
        }

        Node *current = head;

        for (int i = 1;
             i < position - 1 && current != nullptr;
             i++)
        {
            current = current->next;
        }

        if (current == nullptr || current->next == nullptr)
        {
            return false;
        }

        Node *nodeToDelete = current->next;
        current->next = nodeToDelete->next;

        delete nodeToDelete;
        return true;
    }

    // 7. Traversal
    void traverse() const
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }

        const Node *current = head;

        while (current != nullptr)
        {
            cout << current->data;

            if (current->next != nullptr)
            {
                cout << " -> ";
            }

            current = current->next;
        }

        cout << " -> NULL\n";
    }
};

int main()
{
    SinglyLinkedList list;

    cout << "Initial list: ";
    list.traverse();

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After inserting at end: ";
    list.traverse();

    list.insertAtBeginning(5);

    cout << "After inserting at beginning: ";
    list.traverse();

    if (list.insertAtPosition(15, 3))
    {
        cout << "After inserting 15 at position 3: ";
        list.traverse();
    }
    else
    {
        cout << "Invalid insertion position.\n";
    }

    list.deleteAtBeginning();
    cout << "After deleting at beginning: ";
    list.traverse();

    list.deleteAtEnd();
    cout << "After deleting at end: ";
    list.traverse();

    if (list.deleteAtPosition(2))
    {
        cout << "After deleting position 2: ";
        list.traverse();
    }
    else
    {
        cout << "Invalid deletion position.\n";
    }

    // Edge-case checks
    if (!list.insertAtPosition(99, 100))
    {
        cout << "Insertion rejected: invalid position.\n";
    }

    return 0;
}
