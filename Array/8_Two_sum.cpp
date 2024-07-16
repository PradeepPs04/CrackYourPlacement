#include<bits/stdc++.h>
using namespace std;

void twoSum(vector<int>& nums, int k)
{
    unordered_map<int, int>mpp;
    for(int i = 0; i < nums.size(); i++)
    {
        int req = k - nums[i];
        if(mpp.find(req) != mpp.end())
        {
            cout<<"Pairs are at index: "<<mpp[req]<<","<<i<<endl;
            cout<<"elements are: "<<req<<","<<nums[i]<<endl;
            return;
        }
        mpp[nums[i]] = i;
    }

    cout<<"No pairs found"<<endl;
}

int main()
{
    vector<int>nums = {2,15,11,7};
    twoSum(nums, 9);
    return 0;
}