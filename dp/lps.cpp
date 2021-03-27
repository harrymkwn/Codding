#include<bits/stdc++.h>
using namespace std;

// int longestPalindromeSubseq(string s) {
//     string s1=s, s2 = s;
//     reverse(s2.begin(),s2.end());
//     int m = s1.length(),n=s2.length();
//     vector<vector<int>> dp(m+1,vector<int>(n+1,0));
//     for(int i=0;i<=m;i++)dp[i][0]=0;
//     for(int i=0;i<=n;i++)dp[0][i]=0;
//     for (int i = 1; i <= m; i++)
//         {
//             for (int j = 1; j <= n; j++)
//             {
//                 if (s1[i - 1] == s2[j - 1])
//                 {
//                     dp[i][j] = dp[i-1][j-1] + 1;
//                 }
//                 else
//                 {
//                     dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//     return dp[m][n];       
// }

int longestPalindromeSubseq(string s1) {
    
    int n = s1.length();
    vector<vector<int>> dp(n,vector<int> (n,0));
    for(int i=0;i<n;i++)dp[i][i]=1;
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i + len < n; i++)
        {
            int j = i + len;
            if (s1[i] == s1[j])
            {
                dp[i][j] = dp[i+ 1][j-1]+2;
            }
            else
            {
                dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
            }
        }
    }

    return dp[0][n-1];
}
int main(){
    

    cout<<longestPalindromeSubseq("abcba")<<"\n";
    return 0;
}