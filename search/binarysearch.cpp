#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int binaryHelper(vector<int>array,int start,int end,int target){

    if(start<=end){
        int mid = (start+end)>>1;
        if(array[mid]==target)return mid;
        if(array[mid]>target)return binaryHelper(array,start,mid-1,target);
        return binaryHelper(array,mid+1,end,target);
    }
    return -1;
}

int binarySearch(vector<int> array,int target){
    return binaryHelper(array,0,array.size()-1,target);
}

int main(){
  cout<<binarySearch({0,1,2,3,4,10},10)<<"\n";
  return 0;
}