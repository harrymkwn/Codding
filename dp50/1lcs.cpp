#include<bits/stdc++.h>
using namespace std;


int lcs(string s1,string s2){
    int n=s1.length(),m=s2.size();
    vector<vector<int>> dp(2,vector<int>(m+1,0));
    bool flag=true;
    for(int i=1;i<=n;i++,flag=!flag)
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j])dp[flag][j] = dp[!flag][j-1]+1;
            else dp[flag][j] = max(dp[flag][j-1],dp[!flag][j]);
        }
    return dp[!flag][m];
}

int main(){
    
    vector<vector<int>> dp;
    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2)<<"\n";

    return 0;
}