#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
int countVowelPermutation(int n) {
    vector<vector<long long>> dp(5,vector<long long>(n,0));

    for(int i=0;i<5;i++)dp[i][0] =1;     

    for(int i=1;i<n;i++){
        dp[0][i] = (dp[1][i-1] + dp[2][i-1] + dp[4][i-1])%m;
        dp[1][i] = (dp[0][i-1] + dp[2][i-1])%m;
        dp[2][i] = (dp[1][i-1] + dp[3][i-1])%m;
        dp[3][i] = (dp[2][i-1])%m;
        dp[4][i] = (dp[2][i-1] + dp[3][i-1])%m;
    }

    return (dp[0][n-1] + dp[1][n-1] + dp[2][n-1] + dp[3][n-1] + dp[4][n-1])%m;
}

int main(){
    
    return 0;
}

// a -> e
// e -> a , i
// i -> !i
// o -> i , u
// u -> a


//0   a <- u + e + i  4 + 1 + 2
//1   e <- a + i      0 + 2
//2   i <- e + o      1 + 3
//3   o <- i          2
//4   u <- i + o      2 + 3