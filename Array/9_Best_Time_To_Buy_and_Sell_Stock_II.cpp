#include<bits/stdc++.h>
using namespace std;

void buySellStock2(vector<int>& prices)
{
    int buy = INT_MAX;
    int profit = 0;

    for(auto price:prices)
    {
        if(price < buy) buy = price;
        else    
        {
            profit += (price-buy);
            buy = price;
        }
    }

    cout<<"Max profit: "<<profit<<endl;
}

int main()
{
    vector<int>prices = {7,1,5,3,6,4};
    buySellStock2(prices);
    return 0;
}