#include<bits/stdc++.h>
using namespace std;

vector<string> LCS(vector<vector<int>> &dp,string s1,string s2,int n,int m){

    if(n==0 || m==0){
        vector<string> s(1,"");
        return s;
    }

    if(s1[n-1]==s2[m-1]){ 
        vector<string> arr = LCS(dp,s1,s2,n-1,m-1);

        for(auto &str : arr)
            str.push_back(s1[n-1]);

        return arr;
    }

    if(dp[n-1][m] > dp[n][m-1])return LCS(dp,s1,s2,n-1,m);

    if(dp[n-1][m] < dp[n][m-1])return LCS(dp,s1,s2,n,m-1);

    vector<string> top = LCS(dp,s1,s2,n-1,m);
    vector<string> right = LCS(dp,s1,s2,n,m-1);

    top.insert(top.end(),right.begin(),right.end());

    return top;

}

int lcs(string s1,string s2,vector<vector<int>> &dp){
    int n=s1.length(),m=s2.length();
    dp.resize(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(s1[i]==s2[j])dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
        }
    return dp[n][m];
}

int main(){
    
    vector<vector<int>> dp;
    string s1,s2;
    cin>>s1>>s2;
    int maxlength = lcs(s1,s2,dp);

    vector<string> arr = LCS(dp,s1,s2,s1.size(),s2.size());

    set<string> lcs(arr.begin(),arr.end());
 
    // to copy a vector to a set use set<string> lcs(v.begin(), v.end())
    vector<string> ans;
    // return set containing all LCS
    // return lcs;
    // for(auto str : lcs)if(str.length()==maxlength)ans.push_back(str);
    for(auto str: lcs)cout<<str<<'\n';
    // for(auto str : ans)cout<<str<<"\n";
    return 0;
}