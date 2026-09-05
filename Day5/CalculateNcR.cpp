#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

int calCulateNcR(int n, int r)
{
    int Nfact = factorial(n);
    int Rfact = factorial(r);
    int NmRfact = factorial(n - r);
    int Ncr = Nfact / (Rfact * NmRfact);

    return Ncr;
}

int main()
{

    int n;
    int r;
    cout << "Enter n:";
    cin >> n;
    cout << "Enter r:";
    cin >> r;

    int result = calCulateNcR(n, r);
    cout << "NcR = " << result;

    return 0;
}