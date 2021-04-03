#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
int sum(vector<long long> dp,int n){
    long long temp = 0;
    for(int i=0;i<dp.size();i++){
        if(n!=1 && i==5)continue;
        temp = (temp + dp[i])%m;
    }

    return temp%m;
}
int knightDialer(int n) {
    vector<long long> dp(10,1);

    for(int i=1;i<n;i++){
        vector<long long> temp = dp;
        dp[0] = (temp[4] + temp[6])%m;
        dp[1] = (temp[6] + temp[8])%m;
        dp[2] = (temp[7] + temp[9])%m;
        dp[3] = (temp[4] + temp[8])%m;
        dp[4] = ((temp[3] + temp[9])%m + temp[0])%m;
        dp[6] = ((temp[1] + temp[7])%m + temp[0])%m;
        dp[7] = (temp[2] + temp[6])%m;
        dp[8] = (temp[1] + temp[3])%m;
        dp[9] = (temp[2] + temp[4])%m;
    }
    return sum(dp,n);
}

int main(){
    
    return 0;
}