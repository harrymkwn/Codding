#include<bits/stdc++.h>
using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
        
    vector<int> dp(cost.size(),0);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2;i<=cost.size();i++){
        dp[i] = min(dp[i-1],dp[i-1]) + (cost.size()==i) ? 0 : cost[i];
    }
    return dp[cost.size()];
}

int main(){
    
    return 0;
}