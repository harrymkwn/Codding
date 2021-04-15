#include<bits/stdc++.h>
using namespace std;

bool mostFrequent(vector<int> &arr){

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
    return c>=arr.size()/2;
}

int main(){
    
    vector<int> arr({0,0,1,1,2,2,0,0,0});
    bool ans = mostFrequent(arr);
    if(ans)cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}