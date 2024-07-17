#include<bits/stdc++.h>
using namespace std;

void threeSum(vector<int>& nums)
{
    int n = nums.size();
    vector<vector<int>>ans;

    sort(nums.begin(), nums.end());

    for(int i = 0; i < n; i++)
    {
        if(i > 0 && nums[i] == nums[i-1])   continue; // to avoid duplicates
        int k = 0 - nums[i];
        // use Two sum for remaining 
        int left = i+1;
        int right = n-1;

        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum == k)   
            {
                ans.push_back({nums[i], nums[left], nums[right]});
                left++;
                right--;
                while(left < right && nums[left] == nums[left-1])   left++; // to avoid duplicates
                while(left < right && nums[right] == nums[right+1]) right--; // to avoid duplicates
            }
            else if(sum < k)   left++;
            else    right--;
        }
    }

    cout<<"Pairs are"<<endl;
    for(auto it:ans)    cout<<"{"<<it[0]<<","<<it[1]<<","<<it[2]<<"} ";
}

int main()
{
    vector<int>nums = {-1,0,1,2,-1,-4};
    threeSum(nums);
    return 0;
}