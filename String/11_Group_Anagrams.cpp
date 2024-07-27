#include<bits/stdc++.h>
using namespace std;

void groupAnagram(vector<string>& strs)
{
    unordered_map<string, vector<string>>mpp;

    for(auto it:strs)
    {
        string temp = it;
        sort(temp.begin(), temp.end());
        mpp[temp].push_back(it);
    }

    vector<vector<string>>ans;
    for(auto i:mpp)
    {
        vector<string>temp;
        for(auto j:i.second)  temp.push_back(j);
        ans.push_back(temp); 
    }

    for(auto it:ans)
    {
        for(auto jt:it) cout<<jt<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<string>strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    groupAnagram(strs);
    return 0;
}