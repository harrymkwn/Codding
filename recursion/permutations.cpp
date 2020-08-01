#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void getPermutationsHepler(vector<int> array,vector<vector<int>> &ret,int i){

    if(i==array.size()){ret.push_back(array);return;}
    for(int j=i;j<array.size();j++){
        swap(array[i],array[j]);
        getPermutationsHepler(array,ret,i+1);
        swap(array[i],array[j]);
    }
}

vector<vector<int>> getPermutations(vector<int> array) {
    vector<vector<int>> ret;
    getPermutationsHepler(array,ret,0);
	return ret;
}


int main(){
  vector<vector<int>> ret = getPermutations({1,2,3});
  for(int i=0;i<ret.size();i++){
      for(int j=0;j<ret[i].size();j++)
        cout<<ret[i][j]<<" ";
    cout<<"\n";
  }
  return 0;
}