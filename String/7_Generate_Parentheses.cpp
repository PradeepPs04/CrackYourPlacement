#include<bits/stdc++.h>
using namespace std;

void generate(int open, int close, string str, vector<string>& ans)
{
    if(open == 0 && close == 0)
    {
        ans.push_back(str);
        return;
    }

    if(open > 0)    generate(open-1, close, str + '(', ans);
    if(close > open)    generate(open, close-1, str + ')', ans);
}

void generateParentheses(int n)
{
    vector<string>ans;
    generate(n, n, "", ans);

    cout<<"Possible combinations of " << n<<" ";
    for(auto it:ans)    cout<<it<<", ";
    cout<<endl;
}

int main()
{
    generateParentheses(3);
    generateParentheses(2);
    return 0;
}