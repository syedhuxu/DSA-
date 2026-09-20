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

    // removing one elemetn from the original prices
    int index_to_remove = 2;
    if (index_to_remove >= 0 && index_to_remove < prices.size())
    {
        prices.erase(prices.begin() + index_to_remove);
    }

    // adding one element
    int index_to_insert = 2;
    int new_value = 300;

    if (index_to_insert >= 0 && index_to_insert <= prices.size())
    {
        prices.insert(prices.begin() + index_to_insert, new_value);
    }

    cout << "After removing a price and adding a new one the final results are: " << endl;

    int finalTotal = 0;
    for (int val : prices)
    {
        cout << val << " ";
        finalTotal += val;
    }

    cout << endl
         << "Final total: " << finalTotal << endl;

    return 0;
}