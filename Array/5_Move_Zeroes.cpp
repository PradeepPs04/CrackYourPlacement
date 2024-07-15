#include<bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int>& nums)
{
    int n = nums.size();
    int left = 0;
    for(int right = 0; right < n; right++)
    {
        if(nums[left] != 0) left++;
        else if(nums[left] == 0 && nums[right] != 0)    
        {
            swap(nums[left], nums[right]);
            left++;
        }
    }
}

int main()
{
    vector<int>nums = {0,1,0,3,12};
    moveZeroes(nums);
    cout<<"Updated array: ";
    for(auto it:nums)   cout<<it<<" ";
    return 0;
}