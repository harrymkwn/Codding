#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b,c;
        cin>>a>>b>>c;
        cout<<(a ^ b ^ c ^ min(min(a,b),c) ^ max(max(a,b),c))<<"\n";
    }
    return 0;
}