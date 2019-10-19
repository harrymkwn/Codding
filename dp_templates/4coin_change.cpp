#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin>>n>>w;
    vector<int>coins(n,0);
    for(int i=0;i<n;i++)
        cin>>coins[i];

    int dp[n][w+1]={0};
    for(int i=0;i<=n;i++)
        for(int j=1;j<=w;j++){
                if(coins[i]<j)
                    dp[i][j] = min(dp[i-1][j],dp[i][j-coins[i]]+1);
                else if(coins[i-1]==j)dp[i][j] = 1;
        }
    cout<<dp[n][w];
}