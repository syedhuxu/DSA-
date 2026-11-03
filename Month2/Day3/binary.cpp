
#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

int main()
{

    // Creating nodes
    Node *root = new Node(10);

    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(50);

    root->right->left = new Node(60);
    root->right->right = new Node(70);

    return 0;
}
