
#include<bits/stdc++.h>
using namespace std;
int longestPalindromeSubseq(string s1) {
    
    int n = s1.length();
    vector<vector<int>> dp(n,vector<int> (n,0));
    int maxlen=1,count =n;
    for(int i=0;i<n;i++){dp[i][i]=1;count++;}
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i + len < n; i++)
        {
            int j = i + len;
            if (s1[i] == s1[j] && (dp[i+1][j-1]!=0||len==1))
            {
                count++;
                dp[i][j] = dp[i+ 1][j-1]+2;
            }else dp[i][j]=0;
            if(maxlen<dp[i][j])maxlen=dp[i][j];
        }        
    }

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        cout<<dp[i][j]<<" ";
    }
    cout<<"\n";
    }
    return maxlen;
}
string findLongestPalindromeSubseq(string s1)
{
    int n = s1.length();
    vector<vector<int>> dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)dp[i][i]=1;
    int maxlen=1,savei=0,savej=0;
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i + len < n; i++)
        {
            int j = i + len;
            if (s1[i] == s1[j] && (dp[i+1][j-1]!=0||len==1))
            {
                dp[i][j] = dp[i+ 1][j-1]+2;
                if(maxlen<dp[i][j]){maxlen=dp[i][j];savei=i;savej=j;}
            }
        }        
    }
    return s1.substr(savei,dp[savei][savej]);
}
int main(){
    
    cout<<findLongestPalindromeSubseq("babad")<<"\n";
    return 0;
}