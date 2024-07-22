#include<bits/stdc++.h>
using namespace std;

void firstSolution(int num)
{
     vector<pair<int, string>>mpp = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};

    string ans = "";

    for(int i = 0; i < mpp.size(); i++)
    {
        while(num >= mpp[i].first)
        {
            ans += mpp[i].second;
            num -= mpp[i].first;
        }
    }

    cout<<ans<<endl;
}

void secondSolution(int num)
{
   
    vector<string>ones = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
    vector<string>tens = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
    vector<string>hundreads = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
    vector<string>thousands = {"","M","MM","MMM"};

    string ans = "";

    ans += thousands[num/1000] + hundreads[(num%1000)/100] + tens[(num%100)/10] + ones[(num%10)/1];

    cout<<ans<<endl;
}

int main()
{
    firstSolution(3749);
    secondSolution(58);
    return 0;
}