#include <iostream>
using namespace std;
#include <stack>

int factorial(int n)
{
    stack<int> s;
    int result = 1;

    while (n > 0)
    {
        s.push(n);
        n--;
    }
    while (!s.empty())
    {
        result *= s.top();
        s.pop();
    }
    return result;
}

int main()
{

    cout << "Factorial of 5 is: " << factorial(5) << endl;

    return 0;
}