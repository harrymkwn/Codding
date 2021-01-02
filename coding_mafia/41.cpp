#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int g;
        cin>>g;
        while(g--){
            int i,n,q;
            cin>>i>>n>>q;
            if(n%2==0)cout<<(n/2)<<"\n";
            else if(i==1 && q==1)cout<<(n/2)<<"\n";
            else if (i==1 && q==2)cout<<(n/2)+1<<"\n";
            else if (i==2 && q==2)cout<<(n/2)<<"\n";
            else cout<<(n/2)+1<<"\n";
        }
    }
    return 0;
}