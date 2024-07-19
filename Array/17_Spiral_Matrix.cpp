#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) 
{
    int n = matrix.size();
    int m = matrix[0].size();

    int top = 0, bottom = n-1; // 1st and last row pointer
    int left = 0, right = m-1; // 1st and last column pointer

    vector<int>ans;
    while(top <= bottom && left <= right)
    {
        for(int i = left; i <= right; i++)  ans.push_back(matrix[top][i]); // printing row pointed by top
        top++; // 1 row is done

        for(int i = top; i <= bottom; i++)  ans.push_back(matrix[i][right]); // printing columnn pointed by right
        right--; // 1 column is done


        // these 2 remaining loops will execute when we have finished spiral order 
        // why?

        // because for first 2 loops (top row & right column) we are checking on while loop condition only if they are valid or not
        // but for (bottom row) we are not checking if top has exceeded bottom or not
        // and also for (left column) we are not checking if it exceeds right column or not

        if(top <= bottom)
        {
            for(int i = right; i >= left; i--)  ans.push_back(matrix[bottom][i]); // printing row pointed by bottom
            bottom--; // 1 row is done
        }

        if(left <= right)
        {
            for(int i = bottom; i >= top; i--)  ans.push_back(matrix[i][left]); // printing column pointed by left
            left++; // 1 column is done
        }
    }

    return ans;
}

int main()
{
    vector<vector<int>>matrix = {{1,2,3,4}, {10,11,12,5}, {9,8,7,6}};
    vector<int>ans = spiralOrder(matrix);
    cout<<"Spiral order: ";
    for(auto it:ans)    cout<<it<<" ";
    return 0;
}