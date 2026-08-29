#include <iostream>
using namespace std;

int main()

// Practicing Printing Squares Using Numbers : It's my first pattern btw...
{

    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }

    return 0;
}