#include<bits/stdc++.h>
using namespace std;
bool sieve[INT_MAX];
void sieveOfErathosthese(int n){
    //memset(sieve,true,sizeof(sieve));
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i*i<=n;i++){
        if(sieve[i]){
            for(int j=i*i;j<=n ;j+=i)
                sieve[j]=false;
        }
    }
    for(int i=0;i<=n;i++)
        if(sieve[i])
            cout<<i<<" ";
}


int main(){
    int n;
    cin>>n;
    sieveOfErathosthese(INT_MAX);
}