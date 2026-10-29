#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int val)
    {
        data = val;
        next = prev = NULL;
    }
};

class Dll
{
    Node *head;

public:
    Dll()
    {
        head = NULL;
    }
};

int main()
{

    return 0;
}