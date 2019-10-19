#include <bits/stdc++.h>
using namespace std;
bool find(int * arr,int n,int sum,int **dp){
    if(sum==0)
        return true;
    if(n==0 || sum<0)
        return false;
    if(!dp[n][sum])
        dp[n][sum]=find(arr,n-1,sum,dp);
    if(!dp[n][sum-arr[n-1]] && sum-arr[n-1]>=0)
        dp[n][sum-arr[n-1]] = find(arr,n-1,sum-arr[n-1],dp);
    return dp[n][sum] || dp[n][sum-arr[n-1]];
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)cin>>arr[i];
    int sum;
    cin>>sum;
    int** dp = new int*[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = new int[sum+1];
        for(int j=0;j<=sum+1;j++)
            dp[i][j]=0;
    }
    if(find(arr,n,sum,dp))
        cout<<"Yes\n";
    else 
        cout<<"No\n";
        return 0;
}


bool find(int * arr,int n,int sum,bool **dp){
    if(sum==0)
        return true;
    if(n==0 && sum!=0 || sum<0)
        return false;
    if(!dp[n][sum])
        dp[n][sum]=find(arr,n-1,sum,dp);
    if(!dp[n][sum-arr[n-1]] && sum-arr[n-1]>=0)
        dp[n][sum-arr[n-1]] = find(arr,n-1,sum-arr[n-1],dp);
    if(arr[n-1]>sum)
        return dp[n][sum];
    return dp[n][sum] || dp[n][sum-arr[n-1]];
}
