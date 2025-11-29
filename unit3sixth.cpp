#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return 0;
}

bool isOperand(char c)
{
    return (c >= 'a' && c <= 'z') ||
           (c >= 'A' && c <= 'Z') ||
           (c >= '0' && c <= '9');
}

string infixToPostfix(string infix)
{
    stack<char> st;
    string post = "";

    for (char c : infix)
    {
        if (c == ' ')
            continue;

        if (isOperand(c))
        {
            post += c;
        }
        else if (c == '(')
        {
            st.push(c);
        }
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                post += st.top();
                st.pop();
            }
            st.pop(); // remove '('
        }
        else
        { // operator
            while (!st.empty() && prec(st.top()) >= prec(c) && st.top() != '(')
            {
                post += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // pop remaining operators
    while (!st.empty())
    {
        post += st.top();
        st.pop();
    }

    return post;
}

int main()
{
    string infix = "a-b*c-d/e+f";

    string postfix = infixToPostfix(infix);

    cout << "Infix:   " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}
