#include<bits/stdc++.h>
using namespace std;
//


//Basic Approach
void findTargetSumWaysUtils(vector<int> nums,int i,int s,int target,int &count){

    if(nums.size()==i){
        if(s==target)count++;
        return;
    }

    findTargetSumWaysUtils(nums,i+1,s+nums[i],target,count);
    findTargetSumWaysUtils(nums,i+1,s-nums[i],target,count);
}

int findTargetSumWays(vector<int>& nums, int target) {

    int count =0;
    int sum = accumulate(nums.begin(),nums.end(),0);
    vector<vector<int>> dp(nums.size()+1);
    
    findTargetSumWaysUtils(nums,0,0,target,count);

    return count;   
}



//Knapsack type approach
int findTargetSumWays(vector<int>& nums, int S) {

    int sum = accumulate(nums.begin(),nums.end(),0);
    int knapsackTarget = (sum+S)/2;

    vector<vector<int>> dp(nums.size()+1,vector<int>(knapsackTarget+1));
    for(int i=0;i<=nums.size();i++)dp[i][0]=1;
    for(int i=1;i<=nums.size();i++){
        for(int j=1;j<=knapsackTarget;j++){
            dp[i][j] = dp[i-1][j];
            if(j>=nums[i-1])dp[i][j] += dp[i][j-nums[i-1]];
        }
    }
    return dp[nums.size()][knapsackTarget];
}

int main(){

    int n,x;
    vector<int> arr;
    while (n--)
    {
        cin>>x;
        arr.push_back(x);
    }
    int sum =0;
    cin>>sum;
    cout<<findTargetSumWays(arr,sum)<<"\n";
    
    return 0;
}