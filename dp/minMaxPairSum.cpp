#include<bits/stdc++.h>
using namespace std;

int countBits(int n){

    int count=0;
    while(n){
        n &=(n-1);
        count++;
    }

    return count;
}

pair<int,int> minMaxPairSum(vector<int> arr){
    int n = arr.size();
    vector<int> mi((1<<(n),INT_MAX)),ma((1<<(n)),INT_MIN);

    for(int mask=0;mask<(1<<(n));mask++){
    if(countBits(mask)%2)
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((mask & (1<<i)) && (mask & (1<<j))){
                    int h = mask & ~(1<<i) & ~(1<<j);

                    mi[mask] = min(mi[mask],mi[h] + arr[i] ^arr[j]);
                    ma[mask] = max(ma[mask],ma[h] + arr[i] ^arr[j]);
                }
            }
        }
    }
}

int main(){
    
    return 0;
}