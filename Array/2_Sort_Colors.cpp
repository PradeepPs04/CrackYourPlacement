#include<bits/stdc++.h>
using namespace std;

void sortColors(vector<int>& nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size()-1;

    while(mid < high)
    {
        if(nums[mid] == 0)  
        {
            swap(nums[mid], nums[low]);
            low++;
            mid++;
        }
        else if(nums[mid] == 1) mid++;
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int>nums = {2,0,2,1,1,0};
    sortColors(nums);
    cout<<"Sorted colors: ";
    for(auto it:nums)   cout<<it<<" ";
    return 0;
}