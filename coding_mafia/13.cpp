#include<bits/stdc++.h>
using namespace std;

int findzeros(int n){
    int x=5,count=0;

    while (x<=n)
    {
        count += (n/x);
        x*= 5;
    }
    return count;
}

int main(){
    int t;
    cin>>t;
    int x;
    while(t--){
        cin>>x;
        cout<<findzeros(x)<<"\n";
    }
    return 0;
}