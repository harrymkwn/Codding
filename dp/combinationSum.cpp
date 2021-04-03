#include<bits/stdc++.h>
using namespace std;

int combinationSum4(vector<int>& nums, int target) {

    int n=nums.size();
    vector<long long> dp(target+1,0);
    dp[0]=1;
    for(int i=0;i<=target;i++){
        for(auto x:nums)
            if(i>=x){
                dp[i] +=(long long)dp[i-x]; 
                dp[i] %=2147483647;
            }
    }
    return dp[target];
}

int main(){
    
    return 0;
}