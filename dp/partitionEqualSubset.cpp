#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {

    int sum = accumulate(nums.begin(),nums.end(),0);
    if(sum%2!=0)return false;
    int n=nums.size();
    vector<vector<bool>> dp(2,vector<bool>(sum>>1,false));
    dp[false][0]=true;
    bool flag = false;
    for(int i =0 ;i<n;i++,flag!=flag){
        for(int j=0;j<=sum>>1;j++){
            dp[flag][j] = dp[!flag][j];
            if(j>=nums[i])dp[flag][j] = dp[flag][j] || dp[!flag][j-nums[i]];
        }
    }
    return dp[!flag][sum>>1];
}


int main(){
    
    return 0;
}