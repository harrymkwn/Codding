#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights,vector<int> values,int w,vector<vector<int>> &dp){
    int n=weights.size();

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= weights[i-1])dp[i][j] = max(dp[i][j],dp[i-1][j-weights[i-1]]+ values[i-1]);
        }
    }

    return dp[n][w];
}

int main(){
    int n,w;
    cin>>n;
    vector<int> weights(n,0),values(n,0);
    for(int i=0;i<n;i++)cin>>weights[i];
    for(int i=0;i<n;i++)cin>>values[i];
    cin>>w;
    vector<vector<int>> dp(n+1,vector<int>(w+1,0));

    cout<<knapsack(weights,values,w,dp);
    return 0;
}