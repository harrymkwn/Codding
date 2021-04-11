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



//we are keep track max value after buy a partivular value dp[i-j] + profit[j];
int maxpricwithKTransactions(vector<int>& prices,int k) {
    
    int n = prices.size();
    vector<vector<int>> dp(k+1,vector<int>(n,0));

    for(int i=1;i<=k;i++){
        int maxvalue = dp[i-1][0] - prices[0];
        for(int j=1;j<n;j++){

            dp[i][j] = max(dp[i][j-1],prices[j] + maxvalue);
            maxvalue = max(dp[i-1][j] - prices[j],maxvalue);
            cout<<"("<<dp[i][j]<<","<<maxvalue<<") ";
        }
        cout<<"\n";
    }
    return dp[k][n-1];

}

int maxpricwithAnyNumberTransactions(vector<int> &prices){
    int n = prices.size();
    vector<int> dp(n,0);

    int maxvalue = 0 - prices[0];
    for(int i=1;i<n;i++){

        dp[i] = max(dp[i-1],prices[i] + maxvalue);
        maxvalue = max(dp[i] - prices[i],maxvalue);
        cout<<"("<<dp[i]<<","<<maxvalue<<") ";
    }
    cout<<"\n";
    return dp[n-1];
}

int main(){
    
    vector<int> arr({3,3,5,0,0,3,1,4});

    cout<<maxpricwithKTransactions(arr,2);
    return 0;
}