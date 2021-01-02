#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        float q,p;
        cin>>q>>p;
        printf("%.6f\n",(q>1000 ? p*q*(0.9) : p*q)); 
    }
    return 0;
}