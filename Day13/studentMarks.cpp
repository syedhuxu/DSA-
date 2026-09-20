#include <iostream>
#include <climits>
#include <algorithm>
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

void findHightestAndLowest(int arr[], int sz)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < sz; i++)
    {
        smallest = min(arr[i], smallest);
        largest = max(arr[i], largest);
    }

    cout << "Your lowest score is: " << smallest << endl;
    cout << "Your highest score is: " << largest << endl;
}

int findFailedSubjects(int arr[], int sz)
{
    int failedSubjests = 0;
    for (int i = 0; i < sz; i++)
    {
        if (arr[i] < 40)
        {
            failedSubjests++;
        }
    }
    return failedSubjests;
}

int main()
{
    int arr[5];
    int sz = sizeof(arr) / sizeof(int);

    for (int i = 0; i < sz; i++)
    {
        int marks;
        cout << "Enter Your Marks (0-100): ";
        cin >> marks;
        arr[i] = marks;
    }

    // Total Marks ...
    int totalMarks = calculateTotal(arr, sz);
    cout << "Your Total Marks: " << totalMarks << endl;

    // Average Marks ...
    cout << "Your average is: " << totalMarks / 5 << endl;

    // Highest & Lowest Marks ...
    findHightestAndLowest(arr, sz);

    // Failed subjects ...
    int failedSubs = findFailedSubjects(arr, sz);
    cout << "You are failed in: " << failedSubs << " subjects" << endl;

    // Final result ...
    if (failedSubs >= 1)
    {
        cout << "Your Final Result: Fail" << endl;
    }
    else
    {
        cout << "Your Final Result: Pass" << endl;
    }

    return 0;
}