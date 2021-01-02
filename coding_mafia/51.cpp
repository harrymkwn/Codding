#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        printf("%.2f\n",((float)x + (x>=1500 ? 500 : (float)x*(0.1)) + (x>=1500 ? (float)x * (0.98) : (float)x*(0.9))));
    }
    return 0;
}