#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

ll shash(string const &str)
{
    ll p = 31;
    ll hvalue = 0;
    ll mul = 1;
    F(0, str.size(), i)
    {
        hvalue = (hvalue + ((str[i] - 'a' + 1) * mul) % m) % m;
        mul = (mul * p) % m;
    }

    return hvalue;
}

vector<vector<int>> group_identical (vector<string> const &s){
    int n = s.size();
    vector<pair<ll,int>> hash(n,{0,0});
    F(0,n,i){
        hash[i] = {shash(s[i]),i};
    }
    sort(hash.begin(),hash.end());
    vector<vector<int>> groups;
    F(0,n,i){
        if(i==0 || hash[i].first!=hash[i-1].first)
            groups.emplace_back();
        groups.back().push_back(hash[i].second);
    }

    return groups;
}


int main(){
    int n;
    cin>>n;
    vector<string> s(n);
    F(0,n,i)cin>>s[i];

    vector<vector<int>> groups = group_identical(s);
    F(0,groups.size(),i){
        F(0,groups[i].size(),j){
            cout<<groups[i][j]<<" ";
        }
        cout<<"\n";
    }
  return 0;
}