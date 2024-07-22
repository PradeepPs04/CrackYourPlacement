#include<bits/stdc++.h>
using namespace std;

bool isValid(string s)
{
    stack<char>st;

    for(auto ch:s)
    {
        if(ch == '(' || ch == '[' || ch == '{') st.push(ch);
        else
        {
            if(ch == ')' && !st.empty() && st.top() == '(') st.pop();
            else if(ch == ']' && !st.empty() && st.top() == '[')    st.pop();
            else if(ch == '}' && !st.empty() && st.top() == '{')    st.pop();
            else    return false;
        }
    }

    return st.empty();
}

int main()
{
    string s = "(())([])[{}]";
    if(isValid(s))  cout<<"Valid parentheses"<<endl;
    else    cout<<"Not valid parentheses"<<endl;
}