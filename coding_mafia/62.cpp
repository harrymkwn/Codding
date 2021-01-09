#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>wp(n,0),lr(n,0);
        cin>>wp;
        cin>>lr;
        sort(wp.begin(),wp.end());
        sort(lr.begin(),lr.end());
        int i=n-1,j=n-1;
        int count=0;
        while(i>-1 && j>-1){
            if(wp[i]>lr[j])i--;
            else {count++;i--;j--;}
        }
        cout<<count<<"\n";
    }
    return 0;
}