#define ll long long
#include<bits/stdc++.h>
using namespace std;

void fourSum(vector<int>& nums, int target)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());

    vector<vector<int>>ans;

    for(int i = 0; i < n; i++)
    {
        // handle duplicates
        if(i != 0 && nums[i] == nums[i-1])   continue;
        for(int j = i+1; j < n; j++)
        {
            // handle duplicates
            if(j != i+1 && nums[j] == nums[j-1])  continue;
            ll k = (ll)target - ((ll)nums[i] + (ll)nums[j]);
            int left = j+1;
            int right = n-1;

            while(left < right)
            {
                ll sum = (ll)nums[left] + (ll)nums[right];
                if(sum == k)
                {
                    ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                    left++;
                    right--;
                    // handle duplicate pairs
                    while(left < right && nums[left] == nums[left-1])   left++;
                    while(left < right && nums[right] == nums[right+1]) right--;
                }
                else if(sum < k)    left++;
                else    right--;
            }
        }   

    }
    cout<<"Pairs are"<<endl;
    for(auto it:ans)
        cout<<"{"<<it[0]<<","<<it[1]<<","<<it[2]<<","<<it[3]<<"} ";
}

int main()
{
    vector<int>nums = {1,0,-1,0,-2,2};
    fourSum(nums, 0);
    return 0;
}