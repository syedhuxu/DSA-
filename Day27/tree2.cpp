#include <iostream>
using namespace std;

// Array size 15 le rahy hain (taaki ek 3-level tree easily fit ho jaye)
int tree[15];

// --- 1. INSERTION OPERATIONS ---

void setRoot(int key)
{
    if (tree[0] != -1)
    {
        cout << "Root already exists!" << endl;
    }
    else
    {
        tree[0] = key;
    }
}

void setLeft(int key, int parentIndex)
{
    if (tree[parentIndex] == -1)
    {
        cout << "Parent does not exist at index " << parentIndex << endl;
    }
    else
    {
        tree[(parentIndex * 2) + 1] = key;
    }
}

void setRight(int key, int parentIndex)
{
    if (tree[parentIndex] == -1)
    {
        cout << "Parent does not exist at index " << parentIndex << endl;
    }
    else
    {
        tree[(parentIndex * 2) + 2] = key;
    }
}

// --- 2. SEARCH OPERATION ---

void searchNode(int key)
{
    bool found = false;
    // Array mai simply linear search lagayenge
    for (int i = 0; i < 15; i++)
    {
        if (tree[i] == key)
        {
            cout << "Value " << key << " found at Array Index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Value " << key << " not found in the tree." << endl;
    }
}


// Preorder: ROOT -> LEFT -> RIGHT
void preorder(int index)
{
    // Agar index array size se bahar hai ya node khali hai (-1), toh wapas jao (return)
    if (index >= 15 || tree[index] == -1)
        return;

    cout << tree[index] << " "; // 1. Root print karo
    preorder((index * 2) + 1);  // 2. Left child par jao
    preorder((index * 2) + 2);  // 3. Right child par jao
}

// Inorder: LEFT -> ROOT -> RIGHT
void inorder(int index)
{
    if (index >= 15 || tree[index] == -1)
        return;

    inorder((index * 2) + 1);   // 1. Left child par jao
    cout << tree[index] << " "; // 2. Root print karo
    inorder((index * 2) + 2);   // 3. Right child par jao
}

// Postorder: LEFT -> RIGHT -> ROOT
void postorder(int index)
{
    if (index >= 15 || tree[index] == -1)
        return;

    postorder((index * 2) + 1); // 1. Left child par jao
    postorder((index * 2) + 2); // 2. Right child par jao
    cout << tree[index] << " "; // 3. Root print karo
}

int main()
{
    // Array ko -1 (empty) se initialize kar rahy hain
    for (int i = 0; i < 15; i++)
    {
        tree[i] = -1;
    }

    // Tree Build kar rahy hain (Insertion)
    setRoot(10);
    setLeft(20, 0);  // 10 ka left
    setRight(30, 0); // 10 ka right
    setLeft(40, 1);  // 20 ka left
    setRight(50, 1); // 20 ka right
    setRight(60, 2); // 30 ka right (Index 5 i.e., 30 ka left khali choda hai)

    // Operations Perform kar rahy hain
    cout << "--- Search Operation ---" << endl;
    searchNode(50);
    searchNode(100); // Jo tree mai nahi hai

    cout << "\n--- Tree Traversals ---" << endl;

    cout << "Preorder Traversal: ";
    preorder(0); // Hamesha Root (Index 0) se start karte hain
    cout << endl;

    cout << "Inorder Traversal:  ";
    inorder(0);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(0);
    cout << endl;

    return 0;
}