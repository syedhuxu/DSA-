#include <iostream>
using namespace std;

int main()
{
    // Reverse alphabet triangle
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            cout << char('A' + j - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}