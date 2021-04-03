#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int sum(vector<long long> dp){
    long long temp = 0;
    for(int i=0;i<6;i++){
        temp = (temp + dp[i])%m;
    }
    return temp%m;
}

int dieSimulator(int n, vector<int>& rollMax) {

    vector<vector<long long >> dp(n,vector<long long>(7,0));
    for(int i=0;i<6;i++)dp[0][i]=1;
    dp[0][6] = sum(dp[0]);
    for(int i=1;i<n;i++){
        long long sumval=0;
        for(int j=0;j<6;j++){
            dp[i][j] = dp[i-1][6];
            if(i - rollMax[j]  > 0 )dp[i][j] = (dp[i][j]%m - dp[i-rollMax[j]-1][6]%m + dp[i-rollMax[j]-1][j]%m +m+ m)%m;
            else if(i - rollMax[j] ==0)dp[i][j]--;
            cout<<dp[i][j]<<" ";
            sumval  = (sumval%m + dp[i][j]%m)%m;
        }
        cout<<"\n";
        dp[i][6] = sumval;
    }
    return dp[n-1][6]; 
}
int main(){
    
    return 0;
}