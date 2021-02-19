#include<bits/stdc++.h>
using namespace std;


class abc{
  vector<int> arr;

public:
  abc(vector<int> demo){
    arr = demo;

  }

  void print(){
    for(int x:arr)cout<<x<<" ";

    cout<<"\n";
  }
};

int main(){
  abc* obj = new abc({1,2,3,4,5});
  obj->print();
  return 0;
}