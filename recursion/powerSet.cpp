#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<vector<int>> powerSetHelper(vector<int>array , int idx){
    if(idx<0)return {{}};

    int ele = array[idx];
    vector<vector<int>> subsets = powerSetHelper(array,idx-1);
    int n = subsets.size();
    for(int i=0;i<n;i++){
        vector<int> currentSubSet = subsets[i];
        currentSubSet.push_back(ele);
        subsets.push_back(currentSubSet);
    }
    return subsets;
}

vector<vector<int>> powerset(vector<int> array) {
  return powerSetHelper(array,array.size()-1);
}


int main()
{
    vector<vector<int>> ret = powerset({1, 2, 3});
    for (int i = 0; i < ret.size(); i++)
    {
        for (int j = 0; j < ret[i].size(); j++)
            cout << ret[i][j] << " ";
        cout << "\n";
    }
    return 0;
}