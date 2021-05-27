#include<bits/stdc++.h>
using namespace std;

int _gcd_(int a,int b){
    return b ? _gcd_(b,a%b) : a;
}

int __gcd(int a,int b){
    if(!a || !b){
        return a|b;
    }
    unsigned trailingzeroes = __builtin_ctz(a|b);
    a >>= __builtin_ctz(a);
    do
    {
        b >>= __builtin_ctz(b);
        if(a>b)swap(a,b);
        b -= a;
    } while (b);
    
    return b<<trailingzeroes;
}

int main(){
    cout<<_gcd_(5,3)<<"\n";
    return 0;
}