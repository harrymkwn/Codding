#include<iostream>
using namespace std;


int gcd(int a,int b){
    if(b>a)
        return gcd(b,a);
    if(b==0)
        return a;
        
    return gcd(b,a%b);
}

int main(){
    int n;
    cin>>n;
    int i;
    for(i=n-2;i>=0;i--){
        if(gcd(i,n)==1)
            break;
    }
    cout<<i;
}