#include <iostream>
using namespace std;

int main()
{
    int arr[] = {5, 2, 4, 1};
    int n = 4;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++) // inner loop < n-i-1 tk hi jana chahiye kyu ki agr uss k equal gya toh arr[j+1]  wala index invalid hojaye ga...
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}