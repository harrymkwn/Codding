#include <bits/stdc++.h>
using namespace std;

int coinChange(vector<int>&price,int sum){
    int n = price.size();
    vector<int> dp(sum+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int res=INT_MAX;
        for(int j=price[i-1];j<=sum;j++){
            res = dp[j-price[i-1]];
            if(res!=INT_MAX)
            dp[j] = min(res+1,dp[j]);
        }
    }
    return dp[sum]==INT_MAX ? -1 : dp[sum];
}

int main()
{

    return 0;
}