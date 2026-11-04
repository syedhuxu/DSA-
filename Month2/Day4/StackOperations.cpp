#include <iostream>
using namespace std;
#include <stack>

int main()
{
    // Parentheses Checker

    bool isBalanced(string str)
    {

        stack<char> st;

        for (char ch : str)
        {
            if (ch == ')' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else
            {
                if (st.empty())
                {
                    return false;
                }
                char top = st.top();
                if ((ch == ')' || ch == '}' || ch == ']'))
                {
                    st.pop();
                }
            }
        }
        return st.empty();
    }

    cout << "Hello World";
    return 0;
}