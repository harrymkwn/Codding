#include<bits/stdc++.h>
using namespace std;
template <typename T> istream &operator>>(istream &is, vector<T> &vec){for (auto &v : vec)is >> v;return is;}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n,0);
        cin>>a;
        int first=INT_MAX,second=INT_MAX;
        if(a.size()>1){
            for(int i=0;i<a.size();i++){
                if(a[i]<=first){
                    second = first;
                    first = a[i];
                }
                else if(a[i]<second)second = a[i];
            }
            cout<<first+second<<"\n";
        }
        else if (a.size()==1)cout<<a[0]<<"\n";
        else cout<<"0\n";
    }
    return 0;
}