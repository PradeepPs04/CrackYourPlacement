#include<bits/stdc++.h>
using namespace std;

void canJump(vector<int>& nums)
{
    // if already on last index
    if(nums.size() == 1)    
    {
        cout<<"Yes"<<endl;
        return;
    }

    int minimum_req_jump = 0;
    for(int i = nums.size()-2; i >= 0; i--)
    {
        // we need 1 more jump then previous required jump
        minimum_req_jump++;
        // if we have minimum possible jump then this is our new destination
        if(nums[i] >= minimum_req_jump) minimum_req_jump = 0;
    }

    if(minimum_req_jump == 0)   cout<<"Yes"<<endl;
    else    cout<<"No"<<endl;
}

int main()
{
    vector<int>nums = {2,3,1,1,4};
    vector<int>nums2 = {3,2,1,0,4};
    canJump(nums);
    canJump(nums2);
    return 0;
}