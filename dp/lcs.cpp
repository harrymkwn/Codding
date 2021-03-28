#include<bits/stdc++.h>
using namespace std;

int lcs(string s1,string s2){

    int n =s1.length();
    int m = s2.length();
    cout<<n<<" "<<m<<"\n";
    int dp[n+1][m+1]={0};
    for(int i=0;i<n+1;i++)dp[i][0]=0;
    for(int j=0;j<m+1;j++)dp[0][j]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s1[i-1]==s2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1 ;
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }

    return dp[n][m];
}

int lcsOptimal(string s1,string s2){
    int n=s1.length(),m=s2.size();
    vector<vector<int>> dp(2,vector<int>(m+1,0));
    bool flag=true;
    for(int i=1;i<=n;i++,flag=!flag)
        for(int j=1;j<=m;j++){
            if(s1[i-1]==s2[j-1])dp[flag][j] = dp[!flag][j-1]+1;
            else dp[flag][j] = max(dp[flag][j-1],dp[!flag][j]);
        }
    return dp[!flag][m];
}

vector<string> AllLCS(vector<vector<int>> &dp,string s1,string s2,int n,int m){

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

int lookupforAllLCS(string s1,string s2,vector<vector<int>> &dp){
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
    cout<<lcsOptimal(s1,s2)<<"\n";

    return 0;
}