
#include <bits/stdc++.h>
using namespace std;

// for two string problems
int strpat1(string s1, string s2)
{

    int m = s1.length(),n=s2.length();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i=0;i<=m;i++)dp[i][0]=i;
    for(int i=0;i<=n;i++)dp[0][i]=i;
    for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    /* your code */
                }
                else
                {
                    /* your code */
                }
            }
        }

    return 0;
}


//one string problems
int strpat2(string s1){
    
    int n=s1.length();
    vector<vector<int>> dp(n,vector<int>(n,0));    
    for (int len = 1; len < n; len++)
    {
        for (int i = 0; i + len < n; i++)
        {
            int j = i + len;
            if (s1[i - 1] == s1[j - 1])
            {
                /* Your code */
            }
            else
            {
                /* Your code */
            }
        }
    }
    return 0;
}
