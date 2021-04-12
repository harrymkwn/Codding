#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007


int findunique(vector<vector<int>> &hats){

    set<int> ret;
    for(auto x : hats){
        for(auto y : x){
            ret.insert(y);
        }
    }

    vector<int> unique(ret.begin(),ret.end());
    sort(unique.begin(),unique.end());
    int maxn = unique.back();
    unordered_map<int,int> mp;
    for(int i=0;i<unique.size();i++){
        mp[unique[i]] = (i);
    }
    
    for(auto &x : hats){
        for(auto &y : x){
            y = mp[y];
        }
    }
    
    return maxn;
}

long long numberWaysUtils(vector<vector<int>> &hats,int i,long long mask,unordered_map<long long,long long> &dp){

    if(i==hats.size())return 1;

    if(dp.find(mask)!=dp.end())return dp[mask];

    long long temp = 0;
    for(int j=0;j<hats[i].size();j++){
        if(mask & ((long long)1<<hats[i][j]))
            temp = (temp+ numberWaysUtils(hats,i+1,mask^((long long)1<<hats[i][j]),dp))%mod;
    }

    return dp[mask] = temp;
}

int numberWays(vector<vector<int>>& hats) {

    int n = findunique(hats);
    
    unordered_map<long long,long long> dp;

    return numberWaysUtils(hats,0,((long long)1<<(n+1))-1,dp)%mod;
}

int numberWaysIterative(vector<vector<int>>& hats) {

    int n = hats.size();
    
    vector<int> dp(1<<n);
    dp[0]=1;

    vector<vector<int>> persons(40);
    for(int i=0;i<hats.size();i++){
        for(auto x : hats[i]){
            persons[x-1].emplace_back(i);
        }
    }

    for(int i=0;i<40;i++){

        for(int j=(1<<n)-1;j>=0;j--){
            for(int k : persons[i]){
                if((j & (1<<k)) == 0){
                    dp[j | (1<<k)] += dp[j];
                    dp[j | (1<<k)] %= mod;
                }
            }
        }
    }
    return dp[(1<<n) - 1];
}

int main(){
    
    return 0;
}