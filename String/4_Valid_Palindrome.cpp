#include<bits/stdc++.h>
using namespace std;

bool checkPalindrome(string& s, int left, int right)
{
    while(left < right)
    {
        if(s[left] != s[right]) return false;
        left++;
        right--;
    }

    return true;
}

bool validPalindrome(string& s)
{
    int left = 0, right = s.length()-1;
    while(left < right)
    {
        if(s[left] != s[right])
            return checkPalindrome(s, left+1, right) || checkPalindrome(s, left, right-1);
        left++;
        right--;
    }

    return true;
}

int main()
{
    string s1 = "abc";
    string s2 = "abca";
    if(validPalindrome(s1)) cout<<"True"<<endl;
    else    cout<<"False"<<endl;
    if(validPalindrome(s2)) cout<<"True"<<endl;
    else    cout<<"False"<<endl;
    return 0;
}