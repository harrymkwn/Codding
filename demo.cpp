#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int main(){
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,5});
    q.push({0,3});

    cout<<q.top().second;

  return 0;
}   