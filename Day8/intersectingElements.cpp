#include <iostream>
using namespace std;

void intersectingElems(int arr1[], int arr2[], int size1, int size2)
{
    bool isIntersection = false;

    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr2[j] == arr1[i])
            {
                cout << arr1[i] << " ";
            }
        }
    }
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 6};
    int size1 = sizeof(arr1) / sizeof(int);

    int arr2[] = {4, 5, 6, 7, 1, 2, 3};
    int size2 = sizeof(arr2) / sizeof(int);

    intersectingElems(arr1, arr2, size1, size2);
    return 0;
}