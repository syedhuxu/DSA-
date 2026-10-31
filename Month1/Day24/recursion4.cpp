
#include <iostream>
using namespace std;

int fun(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n + fun(n - 1); // here fun(4) waits for fun(3) and fun(3) waits for fun(2) and fun(2) waits for fun(1) which returns 1 and fun(2) receives 1  and adds 1 + 2 = 3 gives 3 to the fun(3) which adds 3 + 3 = 6 gives 6 to fun(4) which adds 4 + 6 = 10 and then returns 10 and prints in main()
}

int main()
{
    cout << fun(4); // 10
    return 0;
}
