#include <iostream>
using namespace std;

int main()
{
    int arr[] = {3, 6, 9, 12, 15};
    int sum = 0;

    for (int i = 0; i < 5; i += 2)
    {
        sum += arr[i];
    }

    cout << sum; // 27
    return 0;
}