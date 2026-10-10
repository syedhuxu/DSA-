#include <iostream>
using namespace std;

int main()
{
    int matrix[3][3] = {
        {0, 5, 0},
        {0, 0, 8},
        {3, 0, 0}};

    int count = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matrix[i][j] != 0)
            {
                count++;
            }
        }
    }

    cout << count;
    return 0;
}