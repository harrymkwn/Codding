#include<bits/stdc++.h>
using namespace std;

int mindiff(vector<int> arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0);
    vector<vector<bool>> dp(n+1,vector<bool>(sum+1,false));
    dp[0][0] = true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i-1]){
                dp[i][j] = dp[i][j] || dp[i-1][j-arr[i-1]];
            }
        }
    }

    int i = sum/2;
    while(i>0 && !dp[n][i]){
        i--;
    }
    return  sum - 2*i;
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<mindiff(arr)<<"\n";
    return 0;
}