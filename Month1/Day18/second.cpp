#include <iostream>
using namespace std;

int main()
{
    int arr[] = {4, 7, 2, 7, 9};
    int target = 8;
    int index = -1;

    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == target)
        {
            index = i;
            break;
        }
    }

    cout << index; // 1
    return 0;
}