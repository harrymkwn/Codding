#include<bits/stdc++.h>
using namespace std;


// Time O(n) && Space O(n)
void usingTempArray(vector<int> &arr,int d){
    int n = arr.size();
    vector<int> temp(n,0);

    for(int i=0;i<n;i++){
        temp[(i+d)%n] = arr[i];
    }

    arr = temp;
}

void leftRotate(vector<int> &arr){
    int n = arr.size();
    if(n<=1)return;
    int temp = arr[0];

    for(int i=0;i<n-1;i++){
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

void rightRotate(vector<int> & arr){
    int n = arr.size();
    if(n<=1)return;
    int temp = arr[n-1];

    for(int i=n-1;i>0;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;

}

//Rotating Solution : Time(n*d) && Space O(1)
void usingRotate(vector<int> &arr,int d){
    for(int i=0;i<d;i++)rightRotate(arr);
}

//Juggeling Method
void juggelingMethod(vector<int> && arr,int d){
    
}

int main(){
    
    vector<int> arr({1,2,3,4,5,6,7,8,9,0});
    usingRotate(arr,3);
    for(auto x : arr)cout<<x<<" ";
    return 0;
}