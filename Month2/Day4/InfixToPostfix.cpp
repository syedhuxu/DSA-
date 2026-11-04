#include <iostream>
#include <stack>
#include <string>

using namespace std;

int precedence(char c)
{

    // Operators ki precedence define karne ke liye function [ '^'  > '/' '*'  '%'  >  '+' '-'  > '(' ')' ]
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*' || c == '%')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

// Infix expression ko Postfix me convert karne ke liye function
string infixToPostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // Agar Operand hai to result me add kar do
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result += c;
        }

        // Agar '(' hai to stack me push kar do
        else if (c == '(')
        {
            st.push('(');
        }
        // Agar ')' hai to stack se pop karte hue result me add kar do jab tak '(' na mile
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            // Agar operator hai to stack me push karne se pehle precedence check karna hoga
            while (!st.empty() && precedence(s[i]) <= precedence(st.top()))
            {
                // Agar operator '^' hai to uski associativity right to left hai, isliye agar stack ke top me bhi '^' hai to break kar do
                if (c == '^' && st.top() == '^')
                {
                    break;
                }

                // Agar current operator ki precedence stack ke top operator se kam ya barabar hai to stack ke top ko result me add kar do aur pop kar do
                result += st.top();
                st.pop();
            }

            // Current operator ko stack me push kar do
            st.push(c);
        }
    }

    // End pe stack me bache hue operators ko result me add kar do
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Infix Expression: " << exp << endl;
    cout << "Postfix Expression: " << infixToPostfix(exp) << endl;

    return 0;
}