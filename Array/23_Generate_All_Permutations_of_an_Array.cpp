#include<bits/stdc++.h>
using namespace std;

void generate(vector<int>& arr, int size, vector<int>& visited, set<vector<int>>& st, vector<int>ds)
{
    // base case when we have picked all elements from arry
    if(size == 0)
    {
        st.insert(ds);
        return;
    }

    // check for all indices
    for(int i = 0; i < arr.size(); i++)
    {
        // pick that only if it was previouly not used
        if(!visited[i])
        {
            visited[i] = 1;
            ds.push_back(arr[i]);
            generate(arr, size-1, visited, st, ds);

            // mark index unvisited and remove last picked when backtrack
            visited[i] = 0;
            ds.pop_back();
        }
    }
}

void allPermutations(vector<int>& arr)
{
    int n = arr.size();
    set<vector<int>>st; // to store unique only
    vector<int>visited(n, 0); // to store used indices in a path

    generate(arr, n, visited, st, {});

    vector<vector<int>>ans;
    for(auto it:st) ans.push_back(it);

    cout<<"Unique permutations"<<endl;
    for(auto i:ans)
    {
        for(auto j:i)   cout<<j<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<int>arr = {1,2,3};
    allPermutations(arr);
    return 0;
}   