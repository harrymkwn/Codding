#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,w;
    cin>>n>>w;
    vector<int>weights(n,0);
    for(int i=0;i<n;i++)
        cin>>weights[i];

    bool dp[n+1][w+1]={false};
    for(int i=0;i<=n;i++)dp[i][0]=true;
    for(int i=0;i<=w;i++)dp[0][i]=true;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++){
                dp[i][j] = dp[i-1][j];
                if(weights[i-1]<=j)
                    dp[i][j] = dp[i][j] || dp[i][j-weights[i-1]];
        }
    if(dp[n][w])
        cout<<"there is possible";
    else cout<<"there is not possible";
}