#include<bits/stdc++.h>
using namespace std;

int main(){

    valarray<int> varr = {1,2,3,4,5};

    valarray<int>varr2 = varr.apply([](int x){return x+5;});

    for (int i = 0; i < varr.size(); i++)
    {
        cout<<varr[i]<<" ";
    }
    
    cout<<"\n";
    cout<<varr.sum()<<"\n";
    cout<<varr2.sum()<<"\n";

    int a[10] ={0};
    iota(a,a+10,0);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    
}