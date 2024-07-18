#include<bits/stdc++.h>
#define ll long long
using namespace std;

int countReversePairs(vector<int>& left, vector<int>& right, int n1, int n2)
{
    int i = 0, j = 0;
    int cnt = 0;

    while(i < n1 && j < n2)
    {
        // if left[i] is making pairs so all after that will make pairs
        // as array is sorted 
        // and all might make pairs with next also 
        if((ll)left[i] > 2 * (ll)right[j])   
        {
            cnt += (n1-i);
            j++;
        }
        // if left[i] is not making so might next will make
        else    i++;
    }
    return cnt;
}   

void merge(vector<int>& nums, int low, int mid, int high, int &cnt)
{
    int n1 = mid-low+1;
    int n2 = high-mid;

    vector<int>left(n1), right(n2);

    int i = low;
    int j = 0;
    while(i <= mid) left[j++] = nums[i++];
    j = 0;
    while(i <= high)    right[j++] = nums[i++];

    // left and right are 2 sorted arrays count reverse pairs on them
    cnt += countReversePairs(left, right, n1, n2);

    i = low, j = 0;
    int k = 0;

    while(j < n1 && k < n2)
    {
        if(left[j] <= right[k]) nums[i++] = left[j++];
        else    nums[i++] = right[k++]; 
    }

    while(j < n1)   nums[i++] = left[j++];
    while(k < n2)   nums[i++] = right[k++];
}

void mergeSort(vector<int>& nums, int low, int high, int &cnt)
{
    if(low < high)
    {
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid, cnt);
        mergeSort(nums, mid+1, high, cnt);
        merge(nums, low, mid, high, cnt);
    }
}

void reversePairs(vector<int>& nums)
{
    int cnt = 0;
    mergeSort(nums, 0, nums.size()-1, cnt);
    cout<<"ans: "<<cnt<<endl;
}

int main()
{
    vector<int>nums = {1,3,2,3,1};
    vector<int>nums2 = {2,4,3,5,1};
    
    reversePairs(nums);
    reversePairs(nums2);
    return 0;
}