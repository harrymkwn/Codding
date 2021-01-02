#include<bits/stdc++.h>
using namespace std;

int main(){
    int t=0;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        if(x==y)cout<<"=\n";
        else if(x>y)cout<<">\n";
        else cout<<"<\n";
    }
    return 0;
}