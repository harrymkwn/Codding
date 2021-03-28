#include<bits/stdc++.h>
using namespace std;
#define mod 1000000009
const int MAX_CHAR = 256; 

int countSub(string str){ 
    vector<int> last(MAX_CHAR, -1); 
    int n = str.length(); 
    int dp[n+1]; 
    dp[0] = 1; 
    for (int i=1; i<=n; i++) 
    { 
        dp[i] = (int)((long long)2*dp[i-1]+mod)%mod; 
  
        if (last[str[i-1]] != -1) 
            dp[i] = dp[i] - (dp[last[str[i-1]]]); 
  
        last[str[i-1]] = (i-1); 
    } 
    return (dp[n])%mod; 
} 

int numDistinctPatterns(string s1, string s2) {
    int m = s1.length(),n=s2.length();
    vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
    dp[0][0]=1;
    for(int i=0;i<=m;i++)dp[i][0]=1;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}

int main(){return 0;}