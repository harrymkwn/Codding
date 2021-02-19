#include<bits/stdc++.h>
using namespace std;

int rodcut(vector<int> length,vector<int>price,int sum){
    int n = length.size();
    vector<vector<int>> dp(n+1,vector<int>(sum+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j>= length[i-1])dp[i][j] = max(dp[i][j], dp[i][j-length[i-1]] + price[i-1]);
        }
    }
        return dp[n][sum];
}

int main(){
    int n,rod;
    cin>>n>>rod;
    vector<int> length(n,0),price(n,0);
    for(int i=0;i<n;i++) cin>>length[i];
    for(int i=0;i<n;i++) cin>>price[i];

    cout<<rodcut(length,price,rod)<<"\n";
    return 0;
}