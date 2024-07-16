#include<bits/stdc++.h>
using namespace std;

void chocolateDistribution(vector<int>& chocolates, int m)
{
    sort(chocolates.begin(), chocolates.end());
    int left = 0, right = m-1;
    int miniDiff = INT_MAX;

    while(right < chocolates.size())
    {
        int currDiff = chocolates[right] - chocolates[left];
        miniDiff = min(miniDiff, currDiff);
        left++;
        right++;
    }

    cout<<"Minimum difference: "<<miniDiff<<endl;
}

int main()
{
    vector<int>chocolates = {3, 4, 1, 9, 56, 7, 9, 12};
    chocolateDistribution(chocolates, 5);
    return 0;
}