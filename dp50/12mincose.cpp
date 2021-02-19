#include<bits/stdc++.h>
using namespace std;


int mincost(vector<vector<int>> grid, vector<vector<int>> &dp){
    int n=grid.size(),m=grid[0].size();
    dp[0][0] = grid[0][0];
    for(int i=1;i<n;i++)dp[i][0] = dp[i-1][0] + grid[i][0];
    for(int j=1;j<m;j++)dp[0][j] = dp[0][j-1] + grid[0][j];

    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++){
            dp[i][j] = min(dp[i-1][j],dp[i][j-1]) + grid[i][j];
        }

    return dp[n-1][m-1];
}

int findmincost(vector<vector<int>> grid,int n,int m,vector<vector<int>> &dp){
    if(n==0 || m==0)return INT_MAX;

    if(n==1 && m==1)return grid[0][0];

    if(!dp[n-1][m])dp[n-1][m] = findmincost(grid,n-1,m,dp);
    if(!dp[n][m-1])dp[n][m-1] = findmincost(grid,n,m-1,dp);
    dp[n][m] = min(dp[n-1][m],dp[n][m-1]) + grid[n-1][m-1];
    return dp[n][m];

}

int main(){
    vector<vector<int>> grid,dp;
    int n,m;
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));    
    dp.resize(n,vector<int>(m,0));    
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)cin>>grid[i][j];

    cout<<mincost(grid,dp)<<"\n";
    for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cout<<dp[i][j]<<" ";cout<<"\n";}
    return 0;
}