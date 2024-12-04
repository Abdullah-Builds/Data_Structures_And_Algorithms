#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

int precedence(char op)
{
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    return -1;
}

void infixToPostfix(string infix, string &postfix)
{
    stack<char> s;
    for (int i = 0; i < infix.length(); ++i)
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
                postfix += ' ';
                s.pop();
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
}

int evaluatePostfix(string postfix)
{
   
    stack<int> s;
    istringstream iss(postfix);
    string token;
    while (iss >> token)
    {
        if (isdigit(token[0]))
        {
            s.push(stoi(token));
        }
        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();
            switch (token[0])
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            }
        }
    }
    return s.top();
}

int main()
{
    string infix, postfix;
    cout << "Enter an infix expression: ";
    getline(cin, infix);

    infixToPostfix(infix, postfix);
    cout << "Postfix expression: " << postfix << endl;
    
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}