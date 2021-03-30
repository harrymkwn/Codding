#include<bits/stdc++.h>
using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {
    
    int maxv=0;
    int m = matrix.size(),n=matrix[0].size();
    vector<vector<int>> dp(m,vector<int>(n,0));
    for(int i=0;i<m;i++)dp[i][0]=(int)matrix[i][0]-48;
    for(int i=0;i<n;i++)dp[0][i]=(int)matrix[0][i]-48;
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(dp[i][j])dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]) + 1;
            maxv = maxv < dp[i][j] ? dp[i][j] : maxv; 
        }
    }
    return maxv;
}

int main(){
    
    return 0;
}