#include<bits/stdc++.h>
using namespace std;

vector<int> longestIncreasingSubsequence(vector<int> array) {
  vector<int> dp(array.size(),1);
  vector<int> indp(array.size(),INT_MIN);
  int maxInd=0;
  for(int i=0;i<array.size();i++){
      for(int j=0;j<i;j++){
          if(array[i]>array[j] && dp[i] <= dp[j] + 1){
            dp[i] = dp[j] + 1;
            indp[i] = j;
          }
      }
      if(dp[i] >= dp[maxInd]){
          maxInd = i;
      }
  }
    vector<int>ret;
    while (maxInd != INT_MIN)
    {
        ret.push_back(array[maxInd]);
        maxInd = indp[maxInd];
    }
    sort(ret.begin(),ret.end());
  return ret;
}

int main(){
    vector<int> array = {5,7,-24,12,10,2,3,12,5,6,35};
    vector<int> ret = longestIncreasingSubsequence(array);
    return 0;
}