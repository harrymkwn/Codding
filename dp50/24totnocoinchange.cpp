#include<bits/stdc++.h>
using namespace std;


int coinchange(vector<int> arr,int tot){
    int n= arr.size();
    vector<int> dp(tot+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=1;j<=tot;j++){
            if(j>=arr[i])dp[j] += dp[j-arr[i]];
        }
    }
    return dp[tot];
}

int main(){
    int n,tot;
    cin>>n>>tot;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];

    cout<<coinchange(arr,tot)<<"\n";
    return 0;
}