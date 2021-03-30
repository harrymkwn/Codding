#include<bits/stdc++.h>
using namespace std;

int lastStoneWeightII(vector<int>& stones) {

    int sum = accumulate(stones.begin(),stones.end(),0);
    cout<<sum<<"\n";
    vector<vector<int>> dp(stones.size()+1,vector<int>(sum/2+1,0));
    for(int i=0;i<=stones.size();i++)dp[i][0]=0;
    for(int i=1;i<=stones.size();i++){
        for(int j=1;j<=sum/2;j++){
            dp[i][j]= dp[i-1][j];
            if(j>= stones[i-1])dp[i][j] = max(dp[i][j], dp[i-1][j-stones[i-1]]+stones[i-1]);

            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return sum - (dp[stones.size()][sum>>1]<<1);
}

int main(){
    
    return 0;
}