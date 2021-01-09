#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}


int main(){
  set<int> s={1,2,3,4};
  vector<int> arr;
  try{
    cout<<arr.at(5)<<"\n";
  }
  catch(exception& e){
    cout<<"array index out of bound\n";
  }
  return 0;
}