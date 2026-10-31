#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int main()
{
    Node *first = new Node{10, nullptr};
    first->next = new Node{20, nullptr};
    first->next->next = new Node{30, nullptr};

    Node *current = first;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }

    return 0;
}