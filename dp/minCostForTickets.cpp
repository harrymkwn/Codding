#include<bits/stdc++.h>
using namespace std;

class Solution{
    int n ;
    vector<int> a,cost,a1;
    int dp[366] = {} ;

    int up(int x){
        return *lower_bound(a1.begin(),a1.end(),x) ;
    }

    int solve(int x){
        if(x>a.back()) return 0 ;
        if(dp[x]>0) return dp[x] ;
        dp[x] = cost[0] + solve(up(x+1)) ;
        dp[x] = min( cost[1] + solve(up(x+7)),dp[x] ) ;
        dp[x] = min( cost[2] + solve(up(x+30)),dp[x] ) ;
        
        return dp[x] ;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        n = days.size() ;
        a = days ;
        
        a1 = a ;
        a1.push_back(400) ;
        
        cost = costs ;
        int answer = solve(days[0]) ;
        
        //for(int i=0;i<=20;i++) cout<<dp[i]<<" ";
        
        return answer ;
    }
};

int mincostTickets(vector<int>& days, vector<int>& costs) {
    map<int,int> mp;
    map<int,int>:: iterator itr;
    int m=costs.size(),n=days.size();
    for(int i=0;i<days.size();i++){
        mp[days[i]] = i;
    }
    
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int j=1;j<=n;j++)dp[1][j]=dp[1][j-1] + costs[0];
    
    for(int i=2;i<=m;i++){
        for(int j=1;j<=n;j++){
            
            if(j>=costs[i-1]){
                if(j==costs[i-1])dp[i][j] = min(dp[i-1][j],costs[i-1]);
                else {
                    itr = mp.lower_bound(j-costs[i-1] -1);
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-itr->second]+costs[itr->second]);
                }
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}


int main(){
    
    return 0;
}