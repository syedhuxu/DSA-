#include <iostream>
using namespace std;

int calculateBill(int units)
{
    int totalAmout = 0;
    if (units < 0)
    {

        return -1;
    }

    else if (units > 300)
    {
        int remUnits = units - 300;
        totalAmout += remUnits * 10;
        units = units - remUnits;
    }
    if (units >= 201 && units <= 300)
    {
        int remUnits = units - 200;
        totalAmout += remUnits * 7;
        units = units - remUnits;
    }
    if (units >= 101 && units <= 200)
    {
        int remUnits = units - 100;
        totalAmout += remUnits * 5;
        units = units - remUnits;
    }
    if (units <= 100)
    {
        totalAmout += units * 3;
    }
    return totalAmout;
}
int main()
{

    // Units	Price/unit
    // 0–100	₹3
    // 101–200	₹5
    // 201–300	₹7
    // Above 300	₹10

    int units;
    cout << "Enter Units You Have Consumed: ";
    cin >> units;

    int totalBill = calculateBill(units);
    if (totalBill < 0)
    {
        cout << "Invalid units" << endl;
    }
    else if (totalBill <= 300)
    {
        cout << "Your Total Bill Is: $" << totalBill << " Which Indicates Low Consumption" << endl;
    }
    else if (totalBill > 301 && totalBill <= 1500)
    {
        cout << "Your Total Bill Is: $" << totalBill << " Which Indicates Moderate Consumption" << endl;
    }
    else
    {
        cout << "Your Total Bill Is: $" << totalBill << " Which Indicates High Consumption" << endl;
    }

    return 0;
}
