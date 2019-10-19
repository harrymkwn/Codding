#include <bits/stdc++.h>
using namespace std;


int main()
{
    std::ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum;
    cin>>sum;
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=0;i<=sum;i++)
        dp[0][i]=false;
    
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++){
            
            if(arr[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
        }
    if(dp[n][sum])
        cout<<"Yes\n";
    else 
        cout<<"No\n";
        return 0;
}
