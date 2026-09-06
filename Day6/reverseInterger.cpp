#include <iostream>
using namespace std;
int reverseInt(int n)
{
    int ans = 0;
    while (n > 0)

    {
        int rem = n % 10;
        ans = ans * 10 + rem;
        n /= 10;
    }
    return ans;
}
int main()
{

    int reversedInt = reverseInt(125);
    cout << reversedInt << endl;
    cout << 12 / 10 << endl;
    cout << 1 % 10 << endl;
    cout << 1 / 10 << endl;
    return 0;
}