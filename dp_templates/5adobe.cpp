#include <bits/stdc++.h>
using namespace std;

int find_min(vector<int> weights, int m)
{
    int n = weights.size();
    int dp[n + 1][m + 1] = {0};

    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int i = 1; i <= m; i++)
        dp[0][i] = -1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (weights[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else if (j % weights[i-1] ==0){
                    if ((dp[i - 1][j] != -1) && (dp[i][j - weights[i - 1]] != -1 ))
                        dp[i][j] = min(dp[i - 1][j], (dp[i][j - weights[i - 1]] + 1));
                    else if (dp[i - 1][j] == -1 && dp[i][j-weights[i-1]]!=-1)
                            dp[i][j] = dp[i][j - weights[i - 1]] + 1;
                    else if (dp[i][j - weights[i - 1]] == -1 && dp[i-1][j]!=-1)
                            dp[i][j] = dp[i - 1][j];
            }
            else {
                dp[i][j]= dp[i-1][j];
            }
        cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return dp[n][m];
}

int main()
{

    vector<int> weights(5,0);
    weights[0] = 3;
    weights[1] = 2;
    weights[2] = 5;
    weights[3] = 6;
    weights[4] = 7;

    int m = 13;
    cout << find_min(weights, m) << "\n";
}