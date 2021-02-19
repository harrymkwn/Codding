#include<bits/stdc++.h>
using namespace std;

int rodcut(int n){
    vector<int> dp(n+1,0);
    for(int i=0;i<=n;i++)dp[i] = i;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i;j++){
            dp[i] = max(dp[i],dp[i-j]*j);
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<rodcut(n)<<"\n";
    return 0;
}