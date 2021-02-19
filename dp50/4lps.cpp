#include<bits/stdc++.h>
using namespace std;

int lps(string s1,int i,int j,vector<vector<int>> &dp,int &maxi,int &maxj){
    if(i>j)return 0;


    if(dp[i][j])return dp[i][j];
    if(i==j)return 1;

    
    if(s1[i]==s1[j]){
        dp[i][j] =  lps(s1,i+1,j-1,dp,maxi,maxj)+2;
        return dp[i][j];
    }

    if(!dp[i+1][j])dp[i+1][j] = lps(s1,i+1,j,dp,maxi,maxj);
    if(!dp[i][j-1])dp[i][j-1] = lps(s1,i,j-1,dp,maxi,maxj);
    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);

    return dp[i][j];
}

int main(){
    string s;
    cin>>s;
    vector<vector<int>> dp(s.length()+1,vector<int>(s.length()+1,0));
    for(int i=0;i<s.length();i++)dp[i][i]=1;
    int maxi=0,maxj=0;
    cout<<lps(s,0,s.length()-1,dp,maxi,maxj)<<"\n";
    cout<<s.substr(maxi,(maxj-maxi+1))<<"\n";
    return 0;
}