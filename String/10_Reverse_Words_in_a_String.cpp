#include<bits/stdc++.h>
using namespace std;

void reverseWords(string& s)
{
    // reverse string
    reverse(s.begin(), s.end());

    int n = s.length();
    int left = 0, right = 0, i = 0;

    while(i < n)
    {
        // skip extra spaces
        while(i < n && s[i] == ' ') i++;
        // if we reach end by ignoring spaces
        // it means that string has trailing spaces
        if(i == n)  break;

        // place characters at their correct position
        while(i < n && s[i] != ' ') s[right++] = s[i++];

        // reverse word from [left-right]
        reverse(s.begin()+left, s.begin()+right);

        // add space after word
        s[right++] = ' ';
        left = right;
        i++;
    }

    // resize s
    s.resize(right-1);
    cout<<"Modified string\n"<<s<<endl;
}

int main()
{
    string s = " the sky   is blue ";
    reverseWords(s);
    return 0;
}