#include <bits/stdc++.h>
using namespace std;

// int numberOfWaysToMakeChange(int n, vector<int> denoms) {
//   if(n==0)return 1;
//   vector<int>dp(n+1,0);
//   for(auto i : denoms){
//     for(int j=1;j<=n;j++){
//         if(j==i)dp[j] = dp[j] + 1;
//         if(j>i){
//             dp[j] = dp[j] + dp[j-i];
//         }
//     }
//   }
//   return dp[n];
// }

int numberOfWaysToMakeChange(int n, vector<int> denoms) {
  vector<int>dp(n+1,0);
  dp[0]=1;
  for(auto i : denoms){
    for(int j=1;j<=n;j++){
        if(j>=i){
            dp[j] = dp[j] + dp[j-i];
        }
    }
  }
  return dp[n];
}

int main(){
    cout<<numberOfWaysToMakeChange(10,{1,2,3,4,5,6,7,8,9,10});
    return 0;
}
