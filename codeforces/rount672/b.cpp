#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (auto &v : vec) is >> v; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) { os << '['; for (auto v : vec) os << v << ','; os << ']'<<endl; return os; }

void solve(){
    int n;
    cin>>n;
    vector<ll> arr(n,0);
    cin>>arr;
    long long int total=0;
    vector<int> freq(32,0);

    for(int i=0;i<n;i++){
        int b = 32 - __builtin_clz(arr[i]);
        total += (long long int)freq[b];
        freq[b]++;
    }
    cout<<total + freq[0]*(n-1)<<"\n";
}

int main()
{
    int t;
    cin>>t;
    while (t--) solve();
    
    return 0;
}