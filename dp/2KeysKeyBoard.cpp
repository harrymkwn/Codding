#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {

    return (n%2==0) ? pow(2,n/2) : pow(2,n/2) + pow(2,n/4); 
        
}

int main(){
    
    cout<<minSteps(5)<<"\n";
    return 0;
}