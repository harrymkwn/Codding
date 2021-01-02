#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        int gcd = __gcd(x,y);
        long long  lcm = ((long long)x*y)/gcd;
        cout<< gcd <<" " << lcm <<"\n";
    }
    return 0;
}