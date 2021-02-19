#include<bits/stdc++.h>
using namespace std;

// bool partition(vector<int>arr,int n,int cost1,int cost2){
//     if(n<0)return false;
//     if(n==0){
//         if(abs(cost1-cost2)==arr[0])return true;
//         else return false;
//     }

//     return partition(arr,n-1,cost1+arr[n],cost2) || partition(arr,n-1,cost1,cost2+arr[n]);
// }

bool partition(vector<int> arr){
    int n = arr.size();
    int sum = accumulate(arr.begin(),arr.end(),0)/2;
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
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    bool flag = partition(arr);
    if(flag)cout<<"can be parttioned\n";
    else cout<<"can`t be partitioned\n";
    return 0;
}