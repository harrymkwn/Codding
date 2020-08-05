#include <bits/stdc++.h>
using namespace std;

int minRewards(vector<int> scores)
{
    vector<int> dp(scores.size(),1);
    for(int i=1;i<scores.size();i++){
        if(scores[i] > scores[i-1])dp[i] = dp[i-1] + 1;
    }   
    for(int i=scores.size()-1;i>=0;i--){
        if(scores[i] > scores[i+1])dp[i] = max(dp[i] , dp[i+1] + 1);
    }

    return accumulate(dp.begin(),dp.end(),0);
}
