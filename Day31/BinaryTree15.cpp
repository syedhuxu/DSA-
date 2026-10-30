#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// BinaryTree Implementation and Operations.
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

Node *createTree(const vector<int> &arr, int &idx)
{
    if (idx >= arr.size())
        return nullptr;

    if (arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }

    Node *root = new Node(arr[idx++]);

    root->left = createTree(arr, idx);
    root->right = createTree(arr, idx);

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};

    int idx = 0;

    Node *root = createTree(nodes, idx);

    cout << "Inorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\n";

    return 0;
}