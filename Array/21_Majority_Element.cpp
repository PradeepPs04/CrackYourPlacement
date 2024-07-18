#include<bits/stdc++.h>
using namespace std;

void majority(vector<int>& nums)
{
    int vote = 0;
    int candidate = nums[0];

    for(auto it:nums)
    {
        if(vote == 0)   candidate = it;
        else if(it == candidate)    vote++;
        else    vote--;
    }

    cout<<"Majority is: "<<candidate<<endl;
}

int main()
{
    vector<int>nums = {3,2,3};
    vector<int>nums2 = {2,2,1,1,1,2,2};
    majority(nums);
    majority(nums2);
    return 0;
}