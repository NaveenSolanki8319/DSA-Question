// Infix to Prefix is same as Infix to postfix but changes you made to do:-
// 1. reverse string
// 2. replace '(' by ')' and ')' by '(' in for loop 
// 3. reverse result string

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

int main()
{
    cout << "Enter Your Expression => ";
    string str;
    cin >> str;
    reverse(str.begin(),str.end());
    cout << endl;
    string res = "";
    stack<char> s1;

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ')')
        {
            s1.push(')');
        }
        else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')||(str[i]>='0' && str[i]<='9'))
        {
            res += str[i];
        }
        else if (str[i] == '(')
        {
            while (!s1.empty() && s1.top() != ')')
            {
                res = res + s1.top();
                s1.pop();
            }
            if (!s1.empty())
            {
                s1.pop(); // Popping '(' here
            }
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '^')
        {
            while (!s1.empty() && priority(str[i]) <= priority(s1.top()))
            {
                res = res + s1.top();
                s1.pop();
            }
            s1.push(str[i]);
        }
    }
    while (!s1.empty())
    {
        res = res + s1.top();
        s1.pop();
    }
    reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}