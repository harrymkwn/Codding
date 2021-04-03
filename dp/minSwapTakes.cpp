#include<bits/stdc++.h>
using namespace std;

int minSwap(vector<int>& A, vector<int>& B) {
    int n = A.size();
    int swap[n+1],no_swap[n+1];

    swap[0] = 1; // if we swap than it costs
    no_swap[0] = 0; // if we don`t swap than it will no costs
    for(int i=1;i<=n;i++){
        
        swap[i] = no_swap[i] = 10000;
        if(A[i] > A[i-1] && B[i]>B[i-1]){ //if current both values are larger than perticular previous values tha
            swap[i] = min(swap[i],swap[i-1]+1);  // if we swap ith state than need to swap i-1 th stafge also 
            no_swap[i] = min(no_swap[i],no_swap[i-1]); // if we wont`t swap than no need 
        }
        if(A[i] > B[i-1] && B[i] > A[i-1]){
            swap[i] = min(swap[i],no_swap[i-1]+1); //if  we  swap i th step it willl restore from no_swap
            no_swap[i] = min(no_swap[i],swap[i-1]); // if we no swap than need to swap from previous stage
        }
    }
    int minval = min(no_swap[n],swap[n]);

    return minval;        
}

int main(){
    
    return 0;
}