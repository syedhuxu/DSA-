#include <iostream>
using namespace std;

void allUniqueValues(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < size; j++)
        {
            if (i == j)
            {
                continue;
            }
            if (arr[j] == arr[i])
            {
                isUnique = false;
                break;
            }
        }

        if (isUnique == true)
        {
            cout << arr[i] << " ";
        }
    }
}
int main() // all unique values
{
    int arr[] = {1, 2, 3, 4, 5, 1, 5, 3, 9, 8};
    int size = sizeof(arr) / sizeof(int);

    allUniqueValues(arr, size);
    return 0;
}