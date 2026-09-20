#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void findHighestAndLowest(vector<int> &prices, int sz)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;

    for (int i = 0; i < sz; i++)
    {
        smallest = min(prices[i], smallest);
        largest = max(prices[i], largest);
    }
    cout << "Cheapest: " << smallest << endl;
    cout << "Expensive: " << largest << endl;
}

int main()
{
    vector<int> prices = {250, 120, 499, 80, 300};

    // Print all Product prices , total , products above 200
    int total = 0;
    int productsAbove200 = 0;
    for (int val : prices)
    {
        cout << val << " ";
        total += val;
        if (val > 200)
        {
            productsAbove200++;
        }
    }

    cout << endl
         << "Total: " << total << endl;

    cout << "Products Above 200: " << productsAbove200 << endl;

    findHighestAndLowest(prices, prices.size());

    return 0;
}