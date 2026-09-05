#include <iostream>
using namespace std;

void fibonacci(int n)
{
    int t1 = 0, t2 = 1;
    cout << t1 << " " << t2 << " ";
    for (int i = 1; i < n; i++)
    {
        int next = t1 + t2;
        cout << next << " ";

        t1 = t2;
        t2 = next;
    }
}

int main()
{
    fibonacci(10);
    return 0;
}