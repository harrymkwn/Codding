#include<bits/stdc++.h>
using namespace std;

bool isMatch(string s, string p) {
    int m = p.length(),n=s.length();
    vector<vector<bool>> dp(m+1,vector<bool>(n+1,0));
    dp[0][0]=true;
    for(int i=0;i<=m;i++){
        if(p[i-1]=='*')
            dp[i][0] = dp[i-1][0];
    }
    for(int i=1;i<=m;i++){
        // for(int j=0;j<i;j++)cout<<"0 ";
        cout<<"0 ";
        for(int j=1;j<=n;j++){
            if(p[i-1]=='*')dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else if(p[i-1]=='?')dp[i][j] = (dp[i-1][j-1]==true ? true : false);
            else if(p[i-1]==s[j-1])dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = false;

            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }
    return dp[m][n];
}
int main(){
    
    cout<<isMatch("aab","c*a*b")<<"\n";
    return 0;
}