#include <iostream>
using namespace std;
#include <stack>

int evaluatePostfix(string postfixExp)
{
    stack<int> s;

    int result = 0;
    for (int val : postfixExp)
    {
        if (val == ' ')
        {
            continue;
        }

        if (val >= '0' && val <= '9')
        {
            s.push(val - '0');
        }
        else
        {
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            switch (val)
            {
            case '+':
                result = op1 + op2;
                break;
            case '-':
                result = op1 - op2;
                break;
            case '*':
                result = op1 * op2;
                break;
            case '/':
                result = op1 / op2;
                break;
            }
            s.push(result);
        }
    }
    return s.top();
}

int main()
{

    string postfixExp = "6 3 2 * + 8 2 / -";

    cout << "Postfix Expression: " << postfixExp << endl;

    cout << "After Evaluation: " << evaluatePostfix(postfixExp) << endl;

    return 0;
}