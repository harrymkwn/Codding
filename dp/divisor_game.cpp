#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<bool> arr;
    bool divisorGame(int n) {
        arr.resize(n+1,false);
        for(int i=2;i<=n;i++){
            for(int j=1;j<=sqrt(i);j++){
                if(n%j==0){
                    arr[i] = arr[i] || !arr[i - j];
                }

                if(arr[i])break;
            }
        }
        return arr[n];
    }
};

int main(){
    Solution *obj = new Solution();
    int n;
    while(cin>>n){
        cout<<obj->divisorGame(n)<<"\n";
    }
    return 0;
}