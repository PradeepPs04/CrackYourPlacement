#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums)
{
    int low = 0, high = 1;
    while(high < nums.size())
    {
        if(nums[high] != nums[low])
        {
            low++;
            swap(nums[low], nums[high]);
        }
        high++;
    }
    return low+1;
}

int main()
{
    vector<int>nums = {0,0,1,1,1,2,2,3,3,4};
    int k = removeDuplicates(nums);
    cout<<"Unique elements: ";
    for(int i = 0; i < k; i++)  cout<<nums[i]<<" ";
    return 0; 
}