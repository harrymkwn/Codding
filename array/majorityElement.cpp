#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& arr) {
    int count{0} , prev_ele{arr[0]};

    for(int i=0;i<arr.size();i++){
        if(prev_ele == arr[i])
            count++;
        else  count--;

        if(count==0){
            count=1;
            prev_ele = arr[i];
        }
    }
    int c{0};
    for(auto x : arr){
        if(x==prev_ele)c++;
    }
return c>arr.size()/2 ? prev_ele : -1;
}

vector<int> majorityElementII(vector<int>& nums) {
    int n = nums.size();
    int count1{0},count2{0};
    int prev_ele1 = {-1},prev_ele2{-1};

    for(int i=0;i<n;i++){

        if(prev_ele1==nums[i]){
            count1++;
        }
        else if(prev_ele2==nums[i]){
            count2++;
        }
        else if(count1==0){
            count1=1;
            prev_ele1=nums[i];
        }
        else if(count2){
            count2=1;
            prev_ele2=nums[i];
        }
        else{
            count1--;
            count2--;
        }

    }
    int c1{0},c2{0};
    for(int x : nums){
        if(x==prev_ele1)c1++;
        else if(x==prev_ele2)c2++;
    }

    if(c1>n/3 && c2>n/3)return vector<int>({prev_ele1,prev_ele2});
    else if(c1>n/3)return vector<int>({prev_ele1});
    else if(c2>n/3)return vector<int>({prev_ele2});

    return vector<int>();
}

int main(){
    vector<int> arr({1,1,1,2,3,7,8,1,6,9});
    vector<int> ans = majorityElementII(arr);

    for(int x : ans)cout<<x<<" ";
    return 0;
}