#include <iostream>
using namespace std;

int main()
{
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}};

    for (int i = 0; i < 2; i++)
    { // loop for rows
        int sum = 0;

        for (int j = 0; j < 3; j++)
        { // loop for columns
            sum += matrix[i][j];
        }

        cout << sum << " ";
    }

    return 0;
}