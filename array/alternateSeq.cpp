#include<bits/stdc++.h>
using namespace std;

int minOperations(string s) {
    int c1{0},c2{1},cnt1{0},cnt2{0};

    for(auto x: s){
        cnt1 += x -'0' !=c1;
        cnt2 += x- '0' !=c2;
        swap(c1,c2);
    }  
    return min(c1,c2);  
}
int main(){
    
    return 0;
}