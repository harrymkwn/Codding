#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){for (auto v : vec)os << v << ','; os <<"\n"return os;}
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    cin>>a;
    int odd=0;
    for(int i=0;i<n;i++){
        if(a[i]%2==1)odd++;
    }
    if(odd>=n-odd)cout<<"NOT READY";
    else cout<<"READY FOR BATTLE";
    return 0;
}