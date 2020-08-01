#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int shiftedBinarySearchHelper(vector<int> array, int start,int end ,int target){
    if(start>end)return -1;
    int mid = (start+end)>>1;

    if(array[mid]==target)return mid;
    
    if(array[start]<=array[mid]){
        if(target >= array[start] && target<=array[mid])return shiftedBinarySearchHelper(array,start,mid-1,target);

        return shiftedBinarySearchHelper(array,mid+1,end,target);

    }
    if(target <= array[end] && target >= array[mid+1])return shiftedBinarySearchHelper(array,mid+1,end,target);

    return shiftedBinarySearchHelper(array,start,mid,target);
}

int shiftedBinarySearch(vector<int> array, int target)
{
    return shiftedBinarySearchHelper(array,0,array.size()-1,target);
}

int main()
{
    cout<<shiftedBinarySearch({5,6,7,8,10,11,1,2,3,4},3);
    return 0;
}