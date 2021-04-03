#include <bits/stdc++.h>
using namespace std;

int findNumberOfLIS(vector<int> &nums)
{

  vector<int> dp(nums.size() + 1, 1);
  vector<int> count(nums.size() + 1, 1);

  int lis = 1;
  for (int i = 1; i <= nums.size(); i++)
  {
    for (int j = 1; j < i; j++)
    {
      if (dp[i] < dp[j] + 1 && nums[i - 1] > nums[j - 1]){
        dp[i] = dp[j] + 1;
        count[i] = count[j];
      }
      else if (dp[i] == dp[j] + 1 && nums[i - 1] > nums[j - 1]){
        count[i] += count[j];
      }
    }
  }
  int c = 0;
  
  for (int i = 1; i <= nums.size(); i++)
  {
    if (dp[i] == lis)
      c += count[i];
  }
  return c;
}

//find longest increasing sub sequence
vector<int> longestIncreasingSubsequence(vector<int> array)
{
  vector<int> dp(array.size(), 1);
  vector<int> indp(array.size(), INT_MIN);
  int maxInd = 0;
  for (int i = 0; i < array.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (array[i] > array[j] && dp[i] <= dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
        indp[i] = j;
      }
    }
    if (dp[i] >= dp[maxInd])
    {
      maxInd = i;
    }
  }
  vector<int> ret;
  while (maxInd != INT_MIN)
  {
    ret.push_back(array[maxInd]);
    maxInd = indp[maxInd];
  }
  sort(ret.begin(), ret.end());
  return ret;
}

// find larges lis length
int lengthOfLIS(vector<int> &nums)
{
  vector<int> dp(nums.size(), 1);
  int maxlis = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (nums[j] < nums[i] && dp[i] <= dp[j] + 1)
      {
        dp[i] = dp[j] + 1;
        if (maxlis < dp[i])
          maxlis = dp[i];
      }
    }
  }
  return maxlis;
}

//find length of longest continuous increasing sub sequence
int findLengthOfLCIS(vector<int> &nums)
{
  vector<int> dp(nums.size(), 1);
  int lcis = 0;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] > nums[i - 1])
    {
      dp[i] = dp[i - 1] + 1;
      if (dp[i] > lcis)
        lcis = dp[i];
    }
  }
  return lcis;
}

int main()
{
  vector<int> array = {5, 7, -24, 12, 10, 2, 3, 12, 5, 6, 35};
  vector<int> ret = longestIncreasingSubsequence(array);
  return 0;
}