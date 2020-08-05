#include<bits/stdc++.h>
using namespace std;

bool isOut(int i,int num,vector<int>array){
    if(i==0)return num > array[i+1];
    if(i == array.size()-1)return num < array[i-1];
    return num > array[i+1] ||  num < array[i-1];
}

vector<int> subarraySort(vector<int> array) {
  
  int maxValue = INT_MIN;
  int minValue = INT_MAX;
    for(int i=0;i<array.size();i++){
        if(isOut(i,array[i],array)){
            maxValue = max(maxValue,array[i]);
            minValue = min(minValue,array[i]);
        }
    }
    if(minValue == INT_MAX)return {-1,-1};
    int startIndex = 0;
    while (array[startIndex] < minValue)startIndex++;
    int endIndex = array.size() - 1;
    while (array[endIndex] > maxValue)endIndex++;
    
  return {startIndex,endIndex};
}

int main(){
    vector<int> ret  = subarraySort({1, 2, 8, 4, 5});
    cout<<ret[0]<<" "<<ret[1]<<"\n";
    return 0;
}