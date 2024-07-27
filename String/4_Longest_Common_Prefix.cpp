#include<bits/stdc++.h>
using namespace std;

void longestCommonPrefix(vector<string>& arr)
{
    sort(arr.begin(), arr.end());
    int n = arr.size();
    string ans = "";
    int i = 0;
    while(i < arr[0].size() && i < arr[n-1].size())
    {
        if(arr[0][i] != arr[n-1][i])    break;
        ans += arr[0][i];
        i++;
    }
    
    cout<<"Longest common prefix: "<<ans<<endl;
}

int main()
{
    vector<string>arr = {"flower","flow","flight"};
    vector<string>arr2 = {"dog","racecar","car"};
    longestCommonPrefix(arr);
    longestCommonPrefix(arr2);
    return 0;
}