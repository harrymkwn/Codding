#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/**
 * We want to modify the stack data structure in such a way, that it possible to find the smallest element in the stack in O(1) time, 
 * while maintaining the same asymptotic behavior for adding and removing elements from the stack. 
 * Quick reminder, on a stack we only add and remove elements on one end.
*/
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