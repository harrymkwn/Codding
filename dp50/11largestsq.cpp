#include<bits/stdc++.h>
using namespace std;

int largesqr(vector<vector<int>> grid,vector<vector<int>> &dp){
    int n = grid.size(),maxc=0;
    for(int i=0;i<n;i++)dp[i][0]=grid[i][0];
    for(int i=0;i<grid[0].size();i++)dp[0][i]=grid[0][i];

    for(int i=1;i<n;i++){
        for(int j=1;j<grid[0].size();j++){
            if(grid[i][j]){

                dp[i][j] = min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1]) + 1;
                maxc = maxc < dp[i][j] ? dp[i][j] : maxc;
            }
        }
    }

    return maxc;
}

int main(){
    int n,m;
    vector<vector<int>> grid,dp;
    cin>>n>>m;
    grid.resize(n,vector<int>(m,0));
    dp.resize(n,vector<int>(m,0));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>grid[i][j];
    cout<<largesqr(grid,dp)<<"\n";
    return 0;
}