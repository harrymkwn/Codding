#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    while (t--)
    {
        int n,c;
        cin>>n>>c;
        int x,total=0;
        for(int i=0;i<n;i++){
            cin>>x;
            total+=x;
        }
        if(total<=c)cout<<"YES\n";
        else cout<<"NO\n";

    }
    
    return 0;
}