#include<bits/stdc++.h>
using namespace std;

void subarrayDivByK(vector<int>& nums, int k)
{
    int preSum = 0;
    int cnt = 0;
    unordered_map<int, int>mpp;
    mpp[0] = 1;
    
    for(auto it:nums)
    {
        preSum += it;
        int modd = preSum % k;
        // convert -ve mod to +ve mod
        if(modd < 0)    modd += k;
        // check if it was previouly on hashmap
        cnt += mpp[modd];
        mpp[modd]++;
    }

    cout<<"Ans: "<<cnt<<endl;
}

int main()
{
    vector<int>nums = {-7,2,3,0,-9};
    subarrayDivByK(nums, 3);
    return 0;
}