#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool areBracketsBalanced(std::string expr)
{
    std::stack<char> st;
    int i = 0;
    while (expr[i] != '\0')
    {
        if (
            expr[i] == '{' ||
            expr[i] == '(' ||
            expr[i] == '[')
        {
            st.push(expr[i]);
        }
        else if (expr[i] == '}')
        {
            if (st.top() == '{')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (expr[i] == ')')
        {
            if (st.top() == '(')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else if (expr[i] == ']')
        {
            if (st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        else
        {
        }
        i++;
    }
    return true;
}

// Driver code
int main()
{
    std::string expr = "";

    // Function call
    if (areBracketsBalanced(expr))

        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";

    return 0;
}