#include<bits/stdc++.h>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5};
    cout<<(arr<arr+5)<<"\n"; 
    arr = arr + 1;
    set<int> s;
    auto itr = s.begin();
    itr += 5;
    return 0;
}