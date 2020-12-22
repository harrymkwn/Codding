#include<bits/stdc++.h>
using namespace std;

int main(){
    int x;
    double y;
    cin>>x>>y;

    if(0<x<=2000 && 0<y<=2000) 
        if(x%5==0 && (double)x+0.5 < y)printf("%.2f\n",y-x-0.5);
        else printf("%.2f\n",y);

    return 0;
}