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
int main(){
    string s1,s2;
    cin>>s1;
    cin>>s2;

    cout<<lcs(s1,s2);
}
