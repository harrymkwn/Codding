#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'<<endl; return os; }



void solve(){
    int m,n;
    cin>>n>>m;
    vector<ll> arr(n);
    cin>>arr;
    long long  a =-1e9;
    long long  b =0;

    for(int i=0;i<n;++i){
        ll ah=a,bh=b;
        ah = max(ah,b+arr[i]);
        bh = max(bh,a-arr[i]);
        a=ah;b=bh;
    }
    cout <<a<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while (t--) solve();
    
    return 0;
}