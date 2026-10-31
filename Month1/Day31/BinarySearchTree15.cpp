#include <iostream>
using namespace std;

// BinarySearchTree Implementation and Operations.

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;

    BSTNode(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

BSTNode *insert(BSTNode *root, int key)
{
    if (root == nullptr)
        return new BSTNode(key);

    if (key == root->data)
        return root;

    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

BSTNode *getMinNode(BSTNode *curr)
{
    while (curr != nullptr && curr->left != nullptr)
    {
        curr = curr->left;
    }

    return curr;
}

BSTNode *deleteNode(BSTNode *root, int key)
{
    if (root == nullptr)
        return nullptr;

    if (key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {
        if (root->left == nullptr)
        {
            BSTNode *temp = root->right;
            delete root;
            return temp;
        }

        if (root->right == nullptr)
        {
            BSTNode *temp = root->left;
            delete root;
            return temp;
        }

        BSTNode *successor = getMinNode(root->right);

        root->data = successor->data;

        root->right = deleteNode(root->right, successor->data);
    }

    return root;
}

void inorderBST(BSTNode *root)
{
    if (root == nullptr)
        return;

    inorderBST(root->left);
    cout << root->data << " ";
    inorderBST(root->right);
}

void printTree(BSTNode *root)
{
    if (root == nullptr)
    {
        cout << "BST empty hai!" << endl;
        return;
    }

    inorderBST(root);
    cout << endl;
}

int main()
{
    BSTNode *root = nullptr;

    root = deleteNode(root, 10);

    int keys[] = {50, 30, 70, 20, 40, 60, 80, 50};

    for (int key : keys)
    {
        root = insert(root, key);
    }

    cout << "Initial BST: ";
    printTree(root);

    root = deleteNode(root, 20);
    cout << "After deleting 20: ";
    printTree(root);

    root = deleteNode(root, 30);
    cout << "After deleting 30: ";
    printTree(root);

    root = deleteNode(root, 50);
    cout << "After deleting 50: ";
    printTree(root);

    root = deleteNode(root, 999);

    return 0;
}