#include<bits/stdc++.h>
using namespace std;

void maxScore(vector<int>& points, int k)
{
    int leftSum = 0, rightSum = 0;
    // first pick all K cards from start
    for(int i = 0; i < k; i++)  leftSum += points[i];
    
    if(k == points.size()) // if we have to pick all cards
    {
        cout<<"Max points: "<<leftSum<<endl;
        return;
    }

    int ans = leftSum; 
    // now start removing 1 card from start and pick 1 card from end
    // by doing this we can generate all pairs of k cards we can pick
    int right = points.size()-1;
    for(int left = k-1; left >= 0; left--)
    {
        leftSum -= points[left];
        rightSum += points[right];
        int sum = leftSum + rightSum;

        ans = max(ans, sum); 
        right--;
    }

    cout<<"Max points: "<<ans<<endl;
}

int main()
{
    vector<int>points = {1,79,80,1,1,1,200,1};
    maxScore(points, 3);
    return 0;
}