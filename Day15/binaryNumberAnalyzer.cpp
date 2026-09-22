#include <iostream>
#include <vector>
#include <algorithm> // Required to use the reverse() function
using namespace std;

vector<int> converBinary(int n)
{
    vector<int> resultedNums;

    // Edge case: if input is 0, return a vector with just [0]
    if (n == 0)
    {
        resultedNums.push_back(0);
        return resultedNums;
    }

    while (n > 0)
    {
        int rem = n % 2;
        n /= 2;

        // Push ONLY the individual remainder (0 or 1) into the vector
        resultedNums.push_back(rem);
    }

    // Because remainders are found backwards, reverse the vector to get the correct order
    reverse(resultedNums.begin(), resultedNums.end());

    return resultedNums;
}

int main()
{
    int num;
    cout << "Enter Any Positive Number: ";
    cin >> num;

    vector<int> nums = converBinary(num);
    cout << "Binary: ";
    for (int bit : nums)
    {
        cout << bit;
    }
    cout << endl;
    return 0;
}
