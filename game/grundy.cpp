#include<bits/stdc++.h>
using namespace std;

int getgrundy(unordered_set<int>set){
    int max=0;
    while(set.find(max)!=set.end()){
        max++;
    }
    return max;
    
}

int grundy(int n){
    if(n==0)
        return 0;
    else if(n==6)
        return 6;
    else if(n==2)
        return 2;
    else if(n==3)
        return 3;
    
    unordered_set<int> set;
    set.insert(grundy(n/2));
    set.insert(grundy(n/3));
    set.insert(grundy(n/6));
    return getgrundy(set);
}


int main() {
    int n;
    cin>>n;
    cout<<grundy(n);	
}