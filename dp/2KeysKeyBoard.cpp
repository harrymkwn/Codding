#include<bits/stdc++.h>
using namespace std;

int minSteps(int n) {
    if(n==1)return 0;
    int cur=1,rep=1,count=0;

    while(cur<n){
        count++; //copy increase count
        do {   
            count++;   // paste increase count 
            cur += rep; //paste
        }while((n%cur!=0));
        rep = cur;  //copy snippet        
    }

    return count;
}

int main(){
    
    int n;
    while(cin>>n)
        cout<<minSteps(n)<<"\n";
    return 0;
}