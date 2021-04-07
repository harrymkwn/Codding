#include<bits/stdc++.h>
using namespace std;

long long binpower(int a,int b){
    if(b==0)return a;

    long long res = binpower(a,b/2);
    if(b&1)return res * res * a;
    return res * res;
}

long long binpowerIterative(long long a,long long b,long long m=1000000007){
    a %=m;
    long long res =1;
    while (b>0)
    {
        if(b&1)res = (res * a)%m;
        a = (a * a)%m;
        b >>=1;
    }
    return res;
}

// if m is prime number than we can use x ^ (n mod (m-1)) instead x^n using direct fermet little theorem
long long binpowerIterative2(long long a,long long b,long long m=1000000007){
    a %=m;
    b%= (m-1);
    long long res =1;
    while (b>0)
    {
        if(b&1)res = (res * a)%m;
        a = (a * a)%m;
        b >>=1;
    }
    return res;
}
int main(){
    
    return 0;
}