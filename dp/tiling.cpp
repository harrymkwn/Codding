#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
int numTilings(int N) {

    int dp[N+1];
    fill_n(dp,N+1,0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 5;
    for(int i=4;i<=N;i++){
        dp[i] = ((dp[i-1] * 2)%m + dp[i-3]%m)%m;
    }
    return dp[N];
}

int main(){
    
    return 0;
}