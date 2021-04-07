#include<bits/stdc++.h>
using namespace std;

bool check(vector<int>& nums) {

    int c=0;
    if(nums[0]<nums[nums.size()-1])c++;
    for(int i=1;i<nums.size();i++){
        if(nums[i]<nums[i-1])c++;
        if(c>1)return false;
    }        
    return true;
}

int main(){
    
    return 0;
}