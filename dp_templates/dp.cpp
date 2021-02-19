
#include<bits/stdc++.h>
using namespace std;

#include "dp.h"

int dp::knapSack(vector<int> weights,vector<int> values,int w){
    int n = weights.size();
    vector<vector<int>> dp(2,vector<int>(w+1,0));

    bool flag=true;
    for(int i=0;i<n;i++,flag=!flag){
        for(int j=1;j<=w;j++){
            dp[flag][j] = dp[!flag][j];
            if(j >= weights[i])dp[flag][j] = max(dp[flag][j], values[i] +  dp[!flag][j- weights[i]]);
        }
    }
    return dp[!flag][w];
}