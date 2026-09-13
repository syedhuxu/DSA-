#include <iostream>
using namespace std;

int intersection(int arr1[], int arr2[], int size1, int size2)
{
    int intersectonPoint;
    for (int i = 0; i < size1; i++)
    {
        for (int j = 0; j < size2; j++)
        {
            if (arr2[j] == arr1[i])
            {
                intersectonPoint = arr2[j];
                return intersectonPoint;
            }
        }
    }
    return -1;
}

int main()
{
    int arr1[] = {1, 2, 4, 5};
    int size1 = sizeof(arr1) / sizeof(int);

    int arr2[] = {3, 4, 5, 6, 7};
    int size2 = sizeof(arr2) / sizeof(int);

    int result = intersection(arr1, arr2, size1, size2);
    cout << "First intersection: " << result << endl;
    return 0;
}