#include<bits/stdc++.h>
using namespace std;

int sq(int x){
    return pow(x,2);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int b,ls;
        cin>>b>>ls;
        cout<<(float)sqrt(sq(ls) - sq(b))<<" "<<(float)sqrt(sq(ls) + sq(b))<<"\n";
    }
    return 0;
}