#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        int c=0;
        if(x>=100){
            c= x/100;
            x -= (c*100);
        }
        if(x>=50){
            c++;
            x -= 50;
        }
        if(x>=10){
            c += x/10;
            x -= (x/10)*10;
        }
        if(x>=5){
            c++;
            x -= 5;
        }
        if(x>=2){
            c += x/2;
            x -= (x/2)*2;
        }
        c+= x;
        cout<<c <<"\n"; 
    }
    return 0;
}