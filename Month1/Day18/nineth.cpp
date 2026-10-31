#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *head = new Node{10, nullptr};
    head->next = new Node{30, nullptr};

    Node *newNode = new Node{20, nullptr};

    newNode->next = head->next;
    head->next = newNode;

    Node *current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}