#include<bits/stdc++.h>
using namespace std;

int power(int x,int n,int*dp,int mod){
    if(n==1)
        return x;
    if(!dp[n/2])
        dp[n/2] = (power(x,n/2,dp,mod)+mod)%mod;
    if(n&1)
        return  (int)((long long)x*(long long)dp[n/2]*(long long)dp[n/2] + mod)%mod;
    return (int)((long long)dp[n/2]*(long long)dp[n/2] + mod)%mod;
}

int main(){
    int x,n;
    cin>>x>>n;
    int * dp = new int[n+1];
    for(int i=0;i<=n;i++)dp[i]=0;
    dp[1]==x;
    const int mod=1000000007;
    cout<<power(x,n,dp,mod);
}