#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,x;
    cin>>n;
    int o=0,e=0;
    while (n--)
    {
        cin>>x;
        if(x%2==0)e++;
        else o++;
    }
    cout<<abs(o-e)<<"\n";

    return 0;
}