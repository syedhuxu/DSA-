#include <iostream>
using namespace std;

void printUniqueElems(int arr[], int size)
{
    bool isUnique = true;
    for (int i = 0; i < size; i++)
    {
        bool isUnique = true;
        for (int j = 0; j < size; j++)

        {
            if (i == j)
            {
                continue;
            }

            if (arr[i] == arr[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique == true)
        {
            cout << arr[i] << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 4, 5, 6, 6, 7, 7, 8};
    int size = sizeof(arr) / sizeof(int);
    printUniqueElems(arr, size);

    return 0;
}