#include<bits/stdc++.h>
using namespace std;

void simplifyPath(string& path)
{
    int n = path.length();

    stack<string>st;
    int i = 0;

    while(i < n)
    {
        if(path[i] == '/')
        {
            i++;
            continue;
        }

        string temp;
        while(i < n && path[i] != '/')  temp += path[i++];

        if(temp == "..")
        {
            if(!st.empty()) st.pop();
        }
        else if(temp == ".")    continue;
        else    st.push(temp);
    }

    string ans = "";

    while(!st.empty())
    {
        ans = "/" +  st.top() + ans;
        st.pop();
    }

    cout<<"Simplified path: ";
    cout<<(ans.length() > 0 ? ans : "/")<<endl;
}

int main()
{
    string path = "/home/user/Documents/../Pictures";
    string path2 = "/.../a/../b/c/../d/./";
    simplifyPath(path);
    simplifyPath(path2);
    return 0;
}