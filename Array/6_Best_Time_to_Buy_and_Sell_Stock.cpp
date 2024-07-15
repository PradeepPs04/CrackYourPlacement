#include<bits/stdc++.h>
using namespace std;

void bestTimeToBuyAndSell(vector<int>& prices)
{
    int buy = INT_MAX;
    int profit = 0;

    for(auto price:prices)
    {
        if(price > buy) profit = max(profit, price-buy);
        else    buy = price;
    }

    cout<<"Max profit: "<<profit<<endl;
}

int main()
{
    vector<int>prices = {7,1,5,3,6,4};
    bestTimeToBuyAndSell(prices);
    return 0;
}