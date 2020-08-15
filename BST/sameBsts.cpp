#include <bits/stdc++.h>

using namespace std;

vector<int> getMin(vector<int> arr){
    vector<int> temp;
    for(int i=1;i<arr.size();i++){
        if(arr[0]>arr[i]){
            temp.push_back(arr[i]);
        }
    }
    return temp;
};
vector<int> getMaxOrEqual(vector<int> arr){
    vector<int> temp;
    for(int i=0;i<arr.size();i++){
        if(arr[0]<=arr[i]){
            temp.push_back(arr[i]);
        }
    }
    return temp;
};

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
    if (arrayOne.size() != arrayTwo.size())return false;

    if (arrayOne.size()==0 && arrayTwo.size()==0)return true;

    if (arrayOne[0]!=arrayTwo[0])return false;

    vector<int> leftOne = getMin(arrayOne);
    vector<int> leftTwo = getMin(arrayTwo);
    vector<int> rightOne = getMaxOrEqual(arrayOne);
    vector<int> rightTwo = getMaxOrEqual(arrayTwo);

    return sameBsts(leftOne,leftTwo) && sameBsts(rightOne,rightTwo);
}
