#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,t;
        cin>>n>>t;
        vector<int>a(n,0);
        cin>>a;
        vector<vector<bool>> dp((n+1),vector<bool>(t+1,false));
        for(int i=0;i<=n;i++)dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=t;j++){
                dp[i][j] = dp[i-1][j] ;
                if(j>=a[i-1])dp[i][j] = dp[i][j] || dp[i-1][j-a[i-1]];
            }
        }
        if(dp[n][t])cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}