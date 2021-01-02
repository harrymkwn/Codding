#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int x,c=0;
        cin>>x;
        if(x>2048){
            c = x/2048;
            x -= (c*2048);
        }
        while(x>0){
            x -= pow(2,(int)log2(x));
            c++;
        }
        cout<<c<<"\n";
    }
    return 0;
}