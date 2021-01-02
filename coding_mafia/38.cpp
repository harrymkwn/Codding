#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    int n;
    while(cin>>n){
        if(n==0)break;
        vector<int> a(n+1,0),b(n+1,0);
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[a[i]]=i;
        }
        if(a==b)cout<<"ambiguous\n";
        else cout<<"not ambiguous\n";
    }
    return 0;
}