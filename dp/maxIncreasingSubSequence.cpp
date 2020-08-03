#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> maxSumIncreasingSubsequence(vector<int> array) {
  vector<pair<int,vector<int>>> dp(array.size());
  
  dp[0].first = array[0];
  dp[0].second = {0};
  for(int i=1;i<array.size();i++){
      dp[i].first = array[i];

      for(int j=0;j<i;j++){
          if(array[i] > array[j] && dp[i].first < array[i] + dp[j].first){
              dp[i].first = array[i] + dp[j].first;
              dp[i].second = dp[j].second;
          }
      }

      dp[i].second.push_back(array[i] );
  }
    int maxNum = INT_MIN;
    int maxIND =0;
    for(int i=0;i<dp.size();i++){
        if(maxNum < dp[i].first){
            maxNum = dp[i].first;
            maxIND = i;
        }
    }
  return {
      {maxNum},
      dp[maxIND].second,  
  };
}

int main(){
    vector<int> array = {10,70,20,30,50,11,30};
    vector<vector<int>> ret =  maxSumIncreasingSubsequence(array);
    cout<<ret[0][0]<<"\n";
    for(int i=0;i<ret[1].size();i++){
        cout<<ret[1][i]<<" ";
    }
}