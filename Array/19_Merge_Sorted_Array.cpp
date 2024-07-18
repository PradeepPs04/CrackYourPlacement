#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, vector<int>& nums2, int n, int m)
{
    int i = n-1, j = m-1;
    int idx = n+m-1;

    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j]) nums1[idx--] = nums1[i--];
        else    nums1[idx--] = nums2[j--];
    }

    while(i >= 0)   nums1[idx--] = nums1[i--];
    while(j >= 0)   nums1[idx--] = nums2[j--];

    cout<<"Merged sorted array: ";
    for(auto it:nums1)  cout<<it<<" ";
}

int main()
{
    vector<int>nums1 = {1,2,3,0,0,0};
    vector<int>nums2 = {2,5,6};  
    merge(nums1, nums2, 3, 3);
    return 0;
}