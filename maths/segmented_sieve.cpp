#include<bits/stdc++.h>
using namespace std;
#define max_ele 100001

vector<int>* sieveOfErathosthese(){
    bool sieve[max_ele+1];
    memset(sieve,true,sizeof(sieve));
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i*i<=max_ele;i++){
        if(sieve[i]){
            for(int j=i*i;j<=max_ele ;j+=i)
                sieve[j]=false;
        }
    }
    vector<int>* prime = new vector<int>();
    prime->push_back(2);
    for(int i=3;i<=max_ele;i+=2)
        if(sieve[i])
            prime->push_back(i);
    
    return prime;
}

void printPrimes(long long l,long long r,vector<int>*& prime){
    bool isPrime[r-l+1];
    for(int i=0;i<r-l;i++)
        isPrime[i]=true;

    for(int i=0;prime->at(i)*prime->at(i)<=r;i++){
        int curPrime = prime->at(i);
        long long base = (l/curPrime)*curPrime;
        if(base<l){
            base += curPrime;
        }
        for(long long j=base;j<=r;j+=curPrime){
            isPrime[j-l]=false;
        }
        if(base==curPrime)
            isPrime[base-l]=true;
        
        for(int i=0;i<r-l;i++)
            if(isPrime[i])
            cout<<i+l<<"\n";

    }
    
}

int main(){
    vector<int>*prime   = sieveOfErathosthese();
    int n;
    cin>>n;
    while (n--)
    {
        long long l,r;
        cin>>l>>r;
        printPrimes(l,r,prime);
    }
    

}