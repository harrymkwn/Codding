#include<bits/stdc++.h>
using namespace std;

int deliveryCostUtils(vector<vector<int>> &costs,int i,int s,vector<vector<int>> &dp){

    if(i==(int)costs.size())return 0;

    if(dp[i][s] != -1)return dp[i][s];

    int minvalue=INT_MAX;
    for(int j=0;j<costs.size();j++){
        if(s & (1<<j))
            minvalue = min(minvalue, costs[i][j] + deliveryCostUtils(costs,i+1,s^(1<<j),dp));
    }

    return dp[i][s] = minvalue;

}

int deliveryCost(vector<vector<int>> &costs){
    int s = (1<<(costs.size()+1))-1;

    vector<vector<int>>  dp(costs.size(),vector<int>(1<<(costs.size()+1),-1));
    return deliveryCostUtils(costs,0,s,dp);
}


int main(){
    
    return 0;
}