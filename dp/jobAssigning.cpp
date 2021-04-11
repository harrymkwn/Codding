#include<bits/stdc++.h>
using namespace std;


int dp[10][1<<16];
int jobAssigning(int i,int s,vector<vector<int>> charges){

    if(i==10)return 0;

    if(dp[i][s]!=-1)return dp[i][s];

    int cost=INT_MAX;
    for(int j=0;j<10;i++){
        if(s&(1<<j)){
            cost  = min(cost, charges[i][j] + jobAssigning(i+1,s^(1<<j),charges));
        }
    }

    return dp[i][s] = cost;
}


int main(){
    
    return 0;
}