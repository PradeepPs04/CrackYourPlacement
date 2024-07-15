#include<bits/stdc++.h>
using namespace std;

void findDuplicateNumber(vector<int>& nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    
    slow = nums[0];
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    cout<<"ans: "<<slow<<endl;
}

int main()
{
    vector<int>nums = {3,1,3,4,2};
    findDuplicateNumber(nums);
    return 0;
}