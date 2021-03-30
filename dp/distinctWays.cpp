#include<bits/stdc++.h>
using namespace std;


int disticntWays(int target,vector<int> &ways){

    vector<int> dp(target+1,0);
    dp[0]=1;
    for(int i=1;i<=target;i++){
        for(int j=0;j<ways.size();j++){
            if(i>= ways[i])dp[i] += dp[i-ways[i]];
        }
    }

    return dp[target];
}