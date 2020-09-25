#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
  int n;
  cin>>n;
  while(n--){
      int x;
      cin>>x;
      vector<int> arr(x,0);
      for(int i=0;i<x;i++)cin>>arr[i];
        int freq=0;
        int dec = false;
      for(int i=0;i<x-1;i++){
          dec |= arr[i]<=arr[i+1];
      }
      if(!dec)cout<<"NO\n";
      else cout<<"YES\n";
  }
  return 0;
}