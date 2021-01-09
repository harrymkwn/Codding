#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

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

    int numTrees(int n) {
        int cn = this->ncr(2*n,n)/(n+1);
    }
};

int main(){
    
    return 0;
}