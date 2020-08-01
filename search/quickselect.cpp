#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int quickselect(vector<int> array, int k) {
  map<int ,bool>mp;
  int i=0;
  for(int i=0;i<array.size();i++){
    mp[array[i]]=true;
  }
  map<int,bool>:: iterator itr;

  for(i=0,itr = mp.begin();itr!=mp.end();itr++,i++){
    if(i==k-1){
      return itr->first;
    }
  }
  return -1;
}

int main(){
  cout<<quickselect({1,2,3,4,5,6},3)<<"\n";
  return 0;
}