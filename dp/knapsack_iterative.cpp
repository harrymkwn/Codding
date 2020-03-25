#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int knapsnack(vector<int> val, vector<int> wt, int w, int n){
vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0));
F(1, n + 1, i){
F(1, w + 1, j){
dp[i][j] = dp[i - 1][j];
if (j >= wt[i - 1])
dp[i][j] = max(dp[i][j], dp[i - 1][j - wt[i - 1]] + val[i - 1]);
}
}
return dp[n][w];
}

int main()
{

	vector<int> val = {5, 4, 8, 6};
	vector<int> wt = {1, 2, 3, 5};

	int W = 5;
	int n = 4;

	cout << knapsnack(val, wt, W, n) << endl;
}