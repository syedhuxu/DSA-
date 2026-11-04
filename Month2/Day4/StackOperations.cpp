#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isBalanced(string str)
{
    stack<char> st;

    for (char ch : str)
    {
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']')
        {

            if (st.empty())
            {
                return false;
            }

            char top = st.top();

            if ((ch == ')' && top == '(') ||
                (ch == '}' && top == '{') ||
                (ch == ']' && top == '['))
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{
    string testStr = "{[()]}";

    if (isBalanced(testStr))
    {
        cout << testStr << " is Balanced\n";
    }
    else
    {
        cout << testStr << " is NOT Balanced\n";
    }

    return 0;
}