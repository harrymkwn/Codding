#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n,r=0;
    cin>>t;
    while (t--)
    {      
        r = 0;
        cin>>n;
        while (n>0)
        {
            r = r*10 + n%10;
            n/=10;
        }
        cout<<r<<"\n";
    }
    

    return 0;
}