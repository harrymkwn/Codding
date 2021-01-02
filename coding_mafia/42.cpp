#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,total=0;
        cin>>x;
        while(x>2){
            total += (x-2)/2;
            x-=2;
        }
        cout<<total<<"\n";
    }
    return 0;
}