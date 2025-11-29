#include <iostream>
using namespace std;

char stackArr[100];
int top = -1;

void push(char c) { stackArr[++top] = c; }
char pop() { return (top == -1) ? '\0' : stackArr[top--]; }

bool isMatching(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main()
{
    char s[100];
    cout << "Enter string: ";
    cin >> s;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char c = s[i];

        if (c == '(' || c == '{' || c == '[')
            push(c);
        else
        {
            char open = pop();
            if (!isMatching(open, c))
            {
                cout << "Not Balanced";
                return 0;
            }
        }
    }

    if (top == -1)
        cout << "Balanced";
    else
        cout << "Not Balanced";

    return 0;
}
