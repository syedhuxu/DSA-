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

void countZerosAndOnes(vector<int> &nums)
{

    int zeroCount = 0;
    int oneCount = 0;

    for (int val : nums)
    {
        if (val == 0)
        {
            zeroCount++;
        }
        else
        {
            oneCount++;
        }
    }

    cout << "Total Zeroes: " << zeroCount << endl;
    cout << "Total Ones: " << oneCount << endl;
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

    countZerosAndOnes(nums);

    if (num & 1 == 1)
    {
        cout << "Number is Odd " << endl;
    }
    else
    {
        cout << "Number is Even " << endl;
    }

    if (num > 0 && (num & (num - 1)) == 0)
        cout << "Power of 2";
    else
        cout << "Not a power of 2";

    return 0;
}
