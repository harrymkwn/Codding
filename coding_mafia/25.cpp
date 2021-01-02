#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a,b;
        cin>>a>>b;
        cout<<min(a,b)<<" "<<a+b<<"\n";
    }
    return 0;
}