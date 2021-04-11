#include<bits/stdc++.h>
using namespace std;

int maxpric(vector<unsigned>& prices) {
    int smallest = INT_MAX,diff=INT_MIN;
    for(int i=0;i<prices.size();i++){
        if(smallest>prices[i])smallest=prices[i];

        if(diff<prices[i]-smallest)diff = prices[i]-smallest;
    }        
    return diff;
}

int maxpricwithTwoTransactions(vector<int>& prices) {
    
    int n = prices.size();
    vector<vector<int>> dp(3,vector<int>(n+1,0));

    for(int i=1;i<3;i++){
        int tempMax = dp[i-1][0] - prices[0];
        for(int j=1;j<n;j++){
            dp[i][j] = max(dp[i-1][j],prices[i-1] + tempMax);
            tempMax = max(tempMax,dp[i][j] - prices[i-1]);
            dp[i][j] = max(dp[i][j],tempMax);
        }
    }
    return dp[2][n];
}

int main(){
    
    return 0;
}