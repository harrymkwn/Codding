#include<bits/stdc++.h>
using namespace std;

vector<int> addToArrayForm(vector<int>& num, int k) {
        
    int r=0,prev=0;
    
    for(int i=num.size()-1;i>0;i++){
        int r = k%10;
        k/=10;

        num[i] = num[i] + r + prev;
        if(num[i] > 10){
            prev = num[i]/10;
            num[i] %= 10;
        }else{
            prev = 0;
        }
    }

    if(prev>0)num.insert(num.begin(),prev);

    return num;
}

int main(){
    
    return 0;
}