#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int start[n+1],end[n+1];
    for (int i = 1; i < n; i++)
    {
        int x,y;
        cin>>x>>y;
        start[x]++;
        end[y]++;
    }
    int dp[n+1];
    dp[0]=0;
    for(int i=1;i<=n;i++){
        dp[i]  = start[i] - end[i] +  dp[i-1];
    }
    for(int i=n-1 ;i>0;i--){
        dp[i] += dp[i-1];
    }
    int q;
    cin>>q;
    while (q--)
    {
        int x;
        cin>>x;
        cout<<dp[x]<<"\n";
    }
    
}