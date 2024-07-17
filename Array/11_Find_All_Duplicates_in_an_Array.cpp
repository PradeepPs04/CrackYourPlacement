#include<bits/stdc++.h>
using namespace std;

void findDuplicates(vector<int>& nums)
{
    // all numbers are +ve and in range [1, n]
    // so use array as hash

    vector<int>ans;
    for(int i = 0; i < nums.size(); i++)
    {
        int num = abs(nums[i]);
        // if an index is already visited by some other number 
        // then it's a duplicate
        if(nums[num-1] < 0) ans.push_back(num);
        else    nums[num-1] *= -1; // make it visited
    }

    // make sure to recover the array since we have modified the original array
    for(int i = 0; i < nums.size(); i++)    nums[i] = abs(nums[i]);
    
    cout<<"Duplicates are: ";
    for(auto it:ans)    cout<<it<<" ";
}

int main()
{
    vector<int>nums = {4,3,2,7,8,2,3,1};
    findDuplicates(nums);
    return 0;
}