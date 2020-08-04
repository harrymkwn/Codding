#include <bits/stdc++.h>
using namespace std;

int maxProfitWithKTransactions(vector<int> prices, int k) {
  
    vector<vector<int>> profit(k+1,vector<int>(prices.size(),0));

    for(int t=1;t<k+1;t++){
        int ThusFarmax = INT_MIN;
        for(int l=1;l<prices.size();l++){
            ThusFarmax = max(ThusFarmax, -prices[l-1] + profit[t-1][l-1]);
            profit[t-1][l] = max(prices[l]+ThusFarmax,profit[t][l-1]);
        }
    }
  return profit[k][prices.size()-1];
}
