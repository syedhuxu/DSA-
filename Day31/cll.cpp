#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Cll
{
    Node *head;

public:
    Cll()
    {
        head = NULL;
    }
};

int main()
{

    return 0;
}