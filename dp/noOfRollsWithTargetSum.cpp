#include<bits/stdc++.h>
using namespace std;
#define m 10000000074

int dp[31][1001];
memset(dp,-1,sizeof dp);

int numRollsToTarget(int d, int f, int target) {
    if(target==0 && d==0)return 1;
    if(target <= 0 || d==0)return 0;

    if(dp[d][target]!=-1)return dp[d][target];
    long long temp = 0;
    for(int i=1;i<=f;i++){
        temp = (temp + (numRollsToTarget(d-1,f,target-i))%m)%m;
    }
    return dp[d][target] = temp;
}

int numRollsToTargetIterative(int d, int f, int target) {

    vector<vector<long long>> dp(target+1,vector<long long>(d+1,0));
    dp[0][0]=1;
    for(int i=1;i<=target;i++){
        for(int j=1;j<=d;j++){
            for(int k=1;k<=f;k++){
                if(i>=k)
                    dp[i][j] = (dp[i][j] + dp[i-k][j-1]%m)%m;
            }
        }
    }
    return dp[target][d];
}

int main(){
    
    return 0;
}