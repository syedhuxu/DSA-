#include <iostream>
using namespace std;

// Array size define kar rahy hain (maximum nodes in tree)
char tree[10];

// Function to set the Root node
void root(char key)
{
    if (tree[0] != '\0')
    {
        cout << "Tree already has a root!" << endl;
    }
    else
    {
        tree[0] = key;
        cout << "Root set to " << key << endl;
    }
}

// Function to set the Left Child of a specific parent index
void setLeft(char key, int parentIndex)
{
    if (tree[parentIndex] == '\0')
    {
        cout << "Can't set child, Parent doesn't exist!" << endl;
    }
    else
    {
        // Formula used: 2*i + 1
        int leftIndex = (parentIndex * 2) + 1;
        tree[leftIndex] = key;
        cout << "Left child of " << tree[parentIndex] << " set to " << key << endl;
    }
}

// Function to set the Right Child of a specific parent index
void setRight(char key, int parentIndex)
{
    if (tree[parentIndex] == '\0')
    {
        cout << "Can't set child, Parent doesn't exist!" << endl;
    }
    else
    {
        // Formula used: 2*i + 2
        int rightIndex = (parentIndex * 2) + 2;
        tree[rightIndex] = key;
        cout << "Right child of " << tree[parentIndex] << " set to " << key << endl;
    }
}

// Function to print the array representation of the tree
void printTree()
{
    cout << "\nTree Array Representation: \n";
    for (int i = 0; i < 10; i++)
    {
        if (tree[i] != '\0')
            cout << tree[i] << " ";
        else
            cout << "- "; // Hyphen means empty space
    }
    cout << endl;
}

int main()
{
    // Array initialization with null characters
    for (int i = 0; i < 10; i++)
        tree[i] = '\0';

    // Constructing a basic tree
    root('A');        // Root at index 0
    setLeft('B', 0);  // Left child of A at index 1
    setRight('C', 0); // Right child of A at index 2
    setLeft('D', 1);  // Left child of B at index 3
    setRight('E', 2); // Right child of C at index 6 (Index 4, 5 remain empty)

    printTree();

    return 0;
}