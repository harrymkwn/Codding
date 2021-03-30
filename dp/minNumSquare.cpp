#include<bits/stdc++.h>
using namespace std;

int numSquares(int n) {

    vector<int> squares;
    for(int i=1;i*i <= n;i++)squares.push_back(i*i);

    vector<vector<int>> dp(squares.size()+1,vector<int>(n+1,10000));
    for(int i=0;i<squares.size();i++)dp[i][0]=0;
    for(int i=1;i<=squares.size();i++){
        
        for(int j=0;j<squares[i-1];j++)dp[i][j] = dp[i-1][j];
        for(int j=squares[i-1];j<=n;j++){
            if(dp[i][j-squares[i-1]!=10000])
                dp[i][j] = min(dp[i][j-squares[i-1]]+1,dp[i-1][j]);
        }
    }
    return dp[squares.size()][n];
}

int main(){
    cout<<numSquares(13)<<"\n";
    return 0;
}