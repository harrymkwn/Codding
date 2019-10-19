#include<bits/stdc++.h>
using namespace std;
int s;
int treader(int * arr,int n,bool flag,int k,int dp[][10][2]){
    if(k==0 || 0==n)
        return 0;
    
    if(flag){
        if(!dp[s-n][k-1][0])
            dp[s-n][k-1][0] = treader(arr+1,n-1,false,k-1,dp);
        if(!dp[s-n][k][1])
            dp[s-n][k][1] = treader(arr+1,n-1,true,k,dp);
        int profit1 = arr[0] + dp[s-n][k-1][0];
        int profit2 = dp[s-n][k][1];
        return max(profit1,profit2);
    }
    else
    {   int profit1 =0,profit2=0;
        if(k>0){
            if(!dp[s-n][k][1])
                dp[s-n][k][1] = treader(arr+1,n-1,true,k,dp);
            if(!dp[s-n][k][0])
                dp[s-n][k][0] = treader(arr+1,n-1,false,k,dp);
            profit1 = dp[s-n][k][1] - arr[0];
            profit2 = dp[s-n][k][0];
        }
        return max(profit1,profit2);
    }
}
int main(){
    int t;
    cin>>t;
    int k;
    while(t--){
        int dp[31][10][2] = {0};
        cin>>k;
        cin>>s;
        int arr[s]={0} ;
        for(int i=0;i<s;i++)cin>>arr[i];
        cout<<treader(arr,s,false,k,dp)<<"\n";
    }
    return 0;
}