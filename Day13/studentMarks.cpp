#include <iostream>
using namespace std;

int calculateTotal(int arr[], int sz)
{
    int totalMarks = 0;
    for (int i = 0; i < sz; i++)
    {
        totalMarks += arr[i];
    }
    return totalMarks;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int sz = sizeof(arr) / sizeof(int);

    // for (int i = 0; i < sz; i++)
    // {
    //     int marks;
    //     cout << "Enter Your Marks: ";
    //     cin >> marks;
    //     arr[i] = marks;
    // }

    // Total Marks ...
    int totalMarks = calculateTotal(arr, sz);
    cout << "Your Total Marks: " << totalMarks << endl;

    // Average Marks ...
    cout << "Your average is: " << totalMarks / 5 << endl;

    return 0;
}