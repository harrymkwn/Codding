#include<bits/stdc++.h>
using namespace std;
#define m 1000000007
//TLE
int numWaysUtils(int i,int steps,int arrLen){

    if(steps==0 && i==0)return 1;
    if(steps==0)return 0;
    long long temp=0;

    if(i >0)temp += numWaysUtils(i-1,steps-1,arrLen);
    temp += numWaysUtils(i,steps-1,arrLen);
    if(i<arrLen)temp += numWaysUtils(i+1,steps-1,arrLen);
}

int numWays(int steps, int arrLen) {
    return numWaysUtils(0,steps,arrLen-1);        
}

int numWaysIterative(int steps,int arrLen){
    
    vector<vector<long long>> dp(2,vector<long long> (arrLen+2,0));
    dp[0][1]=1;
    bool flag =true;
    for(int i=1;i<=steps;i++,flag = (!flag)){
        for(int j=1;j<=arrLen;j++){
            dp[flag][j] = (dp[!flag][j-1] + dp[!flag][j] + dp[!flag][j+1])%m;
        }
    }

    return dp[!flag][1]%m;
}

int main(){
    
    return 0;
}