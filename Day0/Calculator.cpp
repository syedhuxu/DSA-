#include <iostream>
using namespace std;

int main()
{
    // Simple Calculator
    int num1, num2;
    char op;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /,%): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    switch (op)
    {
    case '+':
        cout << "Result: " << num1 + num2;
        break;

    case '-':
        cout << "Result: " << num1 - num2;
        break;

    case '*':
        cout << "Result: " << num1 * num2;
        break;

    case '%':
        cout << "Result: " << num1 % num2;
        break;

    case '/':
        if (num2 != 0)
        {
            cout << "Result: " << num1 / num2 << endl;
        }
        else
        {
            cout << "Error: Division by zero is not allowed." << endl;
        }
        break;

    default:
        cout << "Error: Invalid operator!" << endl;
        break;
    }

    return 0;
}