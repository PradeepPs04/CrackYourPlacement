#include<bits/stdc++.h>
using namespace std;

void printDuplicates(string s)
{
    sort(s.begin(), s.end());
    int n = s.length();
    int i = 0;

    while(i < n)
    {
        char ch = s[i];
        int cnt = 0;
        while(i < n && s[i] == ch)
        {
            cnt++;
            i++;
        }  
        if(cnt > 1) cout<<ch<<":"<<cnt<<endl;
    }
}

void printDuplicates2(string s) 
{
    vector<int>mpp(256, 0);

    for(auto ch:s)  mpp[ch]++;

    for(int i = 0; i < 256; i++)
    {
        if(mpp[i] > 1)  cout<<(char)i<<":"<<mpp[i]<<endl;
    }
}

int main()
{
    string s = "geeksforgeeks";
    printDuplicates2(s);
    return 0;
}