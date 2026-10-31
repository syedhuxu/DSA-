#include <iostream>
using namespace std;

int linearSearch(int arr[], int sz, int target)
{
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int main()
{

    int arr[] = {13, 5235, 3412, 32, 53, 65, 33, 234, 01, 44};
    int target = 44;
    int sz = sizeof(arr) / sizeof(int);

    int result = linearSearch(arr, sz, target);
    cout << result << endl;

    return 0;
}