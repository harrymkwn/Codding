#include<bits/stdc++.h>
using namespace std;

void mergeSortHelper(vector<int> &array,int start,int end){
    if(start>=end)return;

    int mid = (start + end)>>1;
    mergeSortHelper(array,start,mid);
    mergeSortHelper(array,mid+1,end);

    int i=start,j=mid+1,k=0;
    vector<int> cache(end-start+1);
    while(i<=mid && j<=end){
        if(array[i]<array[j])
            cache[k++]=array[i++];
        else cache[k++]=array[j++];
    }
    while (i<=mid)cache[k++]=array[i++];
    while (j<=end)cache[k++]=array[j++];
    
    for(int i=start,j=0;i<=end;i++,j++)array[i]=cache[j];
}

vector<int> mergeSort(vector<int> array) {
    if(array.size()<2)return array;
    mergeSortHelper(array,0,array.size()-1);
    // for(int i=0;i<array.size();i++)cout<<array[i]<<" ";
  return array;
}

int main(){
  mergeSort({8,5,2,9,6,5,3});
  return 0;
}