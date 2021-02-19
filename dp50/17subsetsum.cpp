#include<bits/stdc++.h>
using namespace std;

bool partition(vector<int> arr,int sum){
    int n = arr.size();
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0]=true;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1])dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]]; 
        }
    }
    return dp[n][sum];
}

int main(){
    int n,sum;
    cin>>n>>sum;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    bool flag = partition(arr,sum);
    if(flag)cout<<"There is subset whose sume is given\n";
    else cout<<"there is no subset for given sum\n";
    return 0;
}