#include<bits/stdc++.h>
using namespace std;

void minimumWindowSubstring(string& s, string& t)
{
    int mpp[256] = {0};
    for(auto it:t)  mpp[it]++;

    int miniLength = INT_MAX;
    int startIdx = -1;
    int reqCnt = t.length();

    int left = 0, right = 0;

    while(right < s.length())
    {
        if(mpp[s[right]] > 0)  reqCnt--; // check if it is a required character
        mpp[s[right]]--; // include character in window

        while(reqCnt == 0) // shrink window as much as possible
        {
            if(right - left + 1 < miniLength) // get the answer of minimum length
            {
                startIdx = left;
                miniLength = right - left + 1;
            }

            mpp[s[left]]++; // remove character from widnow
            if(mpp[s[left]] == 1)   reqCnt++; // check if removed character was required character
            left++;
        }

        right++; // expand window
    }

    if(startIdx == -1)  cout<<"No valid substring found"<<endl;
    else    cout<<s.substr(startIdx, miniLength)<<endl;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    minimumWindowSubstring(s, t);
    return 0;
}