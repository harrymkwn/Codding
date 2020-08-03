#include <bits/stdc++.h>
using namespace std;

int minNumberOfCoinsForChange(int n, vector<int> denoms)
{
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;    
    for(int i:denoms){
        for(int j=1;j<=n;j++){
            dp[j] = dp[j-1];
            if(j>= i){
                dp[j] = min(dp[j],dp[j-i] + 1);
            }
        }
    }
    return dp[n]==INT_MAX ? -1 : dp[n];
}
