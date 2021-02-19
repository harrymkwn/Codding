#include<bits/stdc++.h>
using namespace std;

int knapsack(vector<int> weights,vector<int>values,int w)
{
    int n = weights.size();
    vector<vector<int>> dp(2,vector<int>(w+1,0));

    bool flag=true;
    for(int i=0;i<n;i++,flag=!flag){
        for(int j=1;j<=w;j++){
            dp[flag][j] = dp[!flag][j];
            if(j >= weights[i])dp[flag][j] = max(dp[flag][j], values[i] +  dp[!flag][j- weights[i]]);
        }
    }
    return dp[!flag][w];
}
int main(){
    int n,w;
    cin>>n>>w;
    vector<int>weights(n,0);
    vector<int>values(n,0);

    for(int i=0;i<n;i++)
        cin>>weights[i];
    for(int i=0;i<n;i++)
        cin>>values[i];

    // int dp[n+1][w+1]={0};
    // for(int i=0;i<=n;i++)dp[i][0]=0;
    // for(int i=0;i<=w;i++)dp[0][i]=0;

    // for(int i=1;i<=n;i++)
    //     for(int j=1;j<=w;j++){
    //             dp[i][j] = dp[i-1][j];
    //             if(weights[i-1]<=j)
    //                 dp[i][j] = max(dp[i][j] , values[i-1] + dp[i-1][j-weights[i-1]]);
    //     }
    cout<<knapsack(weights,values,w)<<"\n";
}