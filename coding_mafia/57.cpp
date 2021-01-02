#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        cin>>a;
        int count=1;
        for(int i=1;i<n;i++){
            if(a[i]>a[i-1])a[i]=a[i-1];
            else count++;
        }
        cout<<count<<"\n";
    }
    return 0;
}