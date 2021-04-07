#include<bits/stdc++.h>
using namespace std;

int arrayPairSum(vector<int>& nums) {
        
    int hash[20001]={0};
    for(int i=0;i<nums.size();i++)hash[nums[i]+10000]++;

    int ret=0;
    bool flag=true;
    for(int i=0;i<20001;){
        if(hash[i]>0 && flag){
            ret += i - 10000;
            hash[i]--;
            flag = !flag;
        }else if(hash[i]>0 && !flag){
            hash[i]--;
            flag = !flag;
        }else i++;
    }
}

int main(){
    
    return 0;
}