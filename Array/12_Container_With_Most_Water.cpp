#include<bits/stdc++.h>
using namespace std;

void maxArea(vector<int>& heights)
{
    int left = 0;
    int right = heights.size()-1;
    int area = 0;
    
    while(left < right)
    {
        int distance = right - left;
        int curArea = min(heights[right], heights[left]) * distance;
        area = max(area, curArea);

        if(heights[left] < heights[right])  left++;
        else    right--;
    }

    cout<<"Max area of water is: "<<area<<endl;
}

int main()
{
    vector<int>heights = {1,8,6,2,5,4,8,3,7};
    maxArea(heights);
    return 0;
}