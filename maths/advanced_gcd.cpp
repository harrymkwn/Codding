#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b>a)return gcd(b,a);
    if(b==0)return a;
    return (b, a%b);
}


int getgcd(int x,string y){

    int mod=0;
    for(int i=y.length()-1;i>=0;i--){
        mod = ((i-'0')*10 + mod)%x;
    }

    return gcd(mod,x);
}


int main(){
    int n;
    cin>>n;
    while (n--)
    {
        int x;
        string y;
        cin>>x>>y;
        cout<<getgcd(x,y)<<"\n";
    }
    
}