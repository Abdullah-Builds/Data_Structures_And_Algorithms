#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
using namespace std;

int precedence(char ch)
{
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    if (ch == '^') return 3;
    return 0;
}

// Helper function to reverse a string and swap '(' with ')'
void reverseAndSwap(string &expr)
{
    reverse(expr.begin(), expr.end());
    for (char &ch : expr)
    {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }
}

void InfixToPrefix(string &infix, string &prefix)
{
    stack<char> s;
    string postfix;

    // Reverse infix and swap parentheses
    reverseAndSwap(infix);

    // Convert to postfix (same logic as before)
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isdigit(ch))
        {
            while (i < infix.length() && isdigit(infix[i]))
            {
                postfix += infix[i++];
            }
            postfix += ' ';
            --i;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.empty() && s.top() != '(')
            {
                postfix += s.top();
                s.pop();
                postfix += ' ';
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && precedence(ch) <= precedence(s.top()))
            {
                postfix += s.top();
                postfix += ' ';
                s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.empty())
    {
        postfix += s.top();
        postfix += ' ';
        s.pop();
    }

    // Reverse postfix to get prefix
    reverse(postfix.begin(), postfix.end());
    prefix = postfix;
}

int solvePrefix(string prefix)
{
    stack<int> s;

    // Process prefix from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        if (isdigit(ch))
        {
            string num;
            while (i >= 0 && isdigit(prefix[i]))
            {
                num += prefix[i--];
            }
            reverse(num.begin(), num.end());
            s.push(stoi(num));
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            int val1 = s.top(); s.pop();
            int val2 = s.top(); s.pop();

            switch (ch)
            {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push(pow(val1, val2)); break;
            }
        }
    }
    return s.top();
}

int main()
{
    string infix = "2*3-5/10";
    string prefix;
    InfixToPrefix(infix, prefix);
    cout << "Prefix: " << prefix << endl;
    cout << "Result: " << solvePrefix(prefix) << endl;
    return 0;
}
