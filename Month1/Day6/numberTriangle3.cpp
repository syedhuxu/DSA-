#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    for (int i = 0; i < n; i++)
    {
        // loop for spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        for (int k = n - i; k > 0; k--)
        {
            cout << i + 1;
        }
        cout << endl;
    }
    return 0;
}