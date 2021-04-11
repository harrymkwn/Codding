#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<pair<int,int>> s;

void adding(int x){
    int new_min = s.empty() ? x : s.back().second;
    s.push_back({x,new_min});
}

void remove(){
    int removed = s.back().first;
    s.pop_back();
}

int min(){
    return s.back().second;
}

int main(){
  
  return 0;
}