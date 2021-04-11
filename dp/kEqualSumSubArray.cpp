#include<bits/stdc++.h>
using namespace std;


bool canPartitionKSubsetsUtils(vector<int>& nums,int k,int s,int sum,const int average,vector<int> &dp){

    if(s==0)return true;
    if(sum>average)return false;

    if(dp[s]!=-1) return dp[s];

    bool flag = false;
    if(sum==average){
        k--;
        sum=0;
        if(k==0)flag=true;
    }
    for(int j=0;j<nums.size() && !flag;j++){
        if(s&(1<<j))
            flag  = flag || canPartitionKSubsetsUtils(nums,k,s^(1<<j),sum+nums[j],average,dp);
    }

    return dp[s] = flag;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {

    // cout<<((1<<(nums.size()+1))-1)<<"\n";
    int total = accumulate(nums.begin(),nums.end(),0);

    int average = total/k;

    vector<int> dp((1<<(nums.size()+1)),-1);


    return canPartitionKSubsetsUtils(nums,k,(1<<(nums.size()+1))-1,0,average,dp); 
}

int main(){
    
    return 0;
}