#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> steps{{-2,-1},{-1,-2},{-2,1},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
unordered_map<string,double> dp;

bool isValid(int n,int r,int c)
{
    if(r<0 || r>=n  || c<0 || c>=n) return false;
    return true;
}

double knightProbabilityUtils(int N,int K,int r,int c,int &total,int &success){
    

    if(K==0){return 1.0;}
    string key = to_string(r) + "|" + to_string(c) + "|" + to_string(K);
    if(dp.find(key)!=dp.end())return dp[key];

    dp[key]=0;
    double answer = 0.0;
    for(int i=0;i<steps.size();i++){
        if(isValid(N,r+steps[i].first,c+steps[i].second))
            answer +=  (1.0*knightProbabilityUtils(N,K-1,r+steps[i].first,c+steps[i].second,total,success))/8;
    }
    dp[key] = answer;
    return dp[key]; 
}

double knightProbability(int N, int K, int r, int c) {

    int success=0,total=0;

    knightProbabilityUtils(N,K,r,c,total,success);

    return ((double)success)/total;       
}

int main(){
    
    return 0;
}