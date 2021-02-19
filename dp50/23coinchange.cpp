#include<bits/stdc++.h>
using namespace std;

int coinchange(vector<int>price,int sum){
    int n = price.size();
    vector<int> dp(sum+1,INT_MAX);
    dp[0]=0;
    for(int i=1;i<=n;i++){
        int res=INT_MAX;
        for(int j=1;j<=sum;j++){

            if(j>= price[i-1])res = dp[j-price[i-1]];

            if(res!=INT_MAX)
            dp[j] = min(res+1,dp[j]);
        }
    }
    return dp[sum];
}

int main(){
    int n,tot;
    cin>>n>>tot;
    vector<int> price(n,0);
    for(int i=0;i<n;i++) cin>>price[i];
    for(int i=0;i<n;i++) cout<<price[i]<<"\n";

    cout<<coinchange(price,tot)<<"\n";
    return 0;
}