#include<bits/stdc++.h>
using namespace std;


long long ncr(int n,int r){
    if(n<r) return 0;
    if(n-r < r)
        r = n-r;

    long long p=1,k=1;
    if(r!=0){
        while (r)
        {
            p*= n;
            k*= r;

            int m = __gcd(p,k);

            p/=m;
            k/=m;

            n--;
            r--;
        }  
        return p;
    }
    else return 1;
}

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n,k;
        cin>>n>>k;
        if(n>=k)cout<<ncr(n-1,k-1)<<"\n";
        else cout<<0<<"\n";
    }
    
}