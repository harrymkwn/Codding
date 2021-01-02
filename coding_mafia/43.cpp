#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        if(x%2==0)cout<<x<<"\n";
        else cout<<x-1<<"\n";
    }
    return 0;
}