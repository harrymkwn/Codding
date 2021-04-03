#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int n,m;
    vector<vector<int>> dp;
    int findPathsUtils(int N,int i,int j){
        
        if(i<0 || j<0 || i>=m || j>=n)return 1;
        
        if(dp[i][j]>0)return dp[i][j];
        
        dp[i][j] += findPathsUtils(N-1,i-1,j);
        dp[i][j] += findPathsUtils(N-1,i,j-1);
        dp[i][j] += findPathsUtils(N-1,i+1,j);
        dp[i][j] += findPathsUtils(N-1,i,j+1);

        return dp[i][j];
    }
    
    int findPaths(int m, int n, int N, int i, int j) {
        this->m = m;
        this->n = n;
        dp.resize(m,vector<int>(n,0));
        findPathsUtils(N,i,j);
    }
};