#include <iostream>
using namespace std;

int digitSum(int num)
{
    int sum = 0;

    while (num > 0)
    {
        int lastDigit = num % 10;
        num = num / 10;
        sum += lastDigit;
    }
    return sum;
}
int main()
{

    int result = digitSum(559);
    cout << result;

    return 0;
}