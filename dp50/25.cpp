#include<bits/stdc++.h>
using namespace std;


int alternatesubseq(vector<int> arr){
    int n = arr.size();

    vector<vector<int>> dp(2,vector<int>(n+1,1));
    int maxv=0;


    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i] > arr[j] && dp[1][i] <= dp[0][j])
                dp[0][i] = dp[1][j] + 1;
        }
        for(int j=i-1;j>=0;j--){
            if(arr[i] < arr[j] && dp[1][i] <= dp[0][j])
                dp[1][i] = dp[0][j] + 1;
        }

        if(maxv < max(dp[0][i],dp[1][i]))maxv = max(dp[0][i],dp[1][i]);
    }
    return maxv;
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
    cout<<alternatesubseq(arr)<<"\n";
    return 0;
}