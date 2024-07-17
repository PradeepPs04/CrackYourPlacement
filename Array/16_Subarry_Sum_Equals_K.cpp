#include<bits/stdc++.h>
using namespace std;

void subarraySum(vector<int>& nums, int k)
{
    unordered_map<int, int>mpp;
    mpp[0] = 1;

    int cnt = 0;
    int preSum = 0;
    for(auto it:nums)
    {
        preSum += it;
        int req = preSum - k;
        cnt += mpp[req];
        mpp[preSum]++;
    }

    cout<<"subarray with sum " << k <<": " << cnt<<endl;
}

int main()
{
    vector<int>nums = {1,2,3};
    subarraySum(nums, 3);
    return 0;
}