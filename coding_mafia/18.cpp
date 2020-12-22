#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int x=1,y=0;
    int maxp=1,max=0;
    int s1=0,s2=0;
    while(t--){
      cin>>x>>y;
      s1 += x;
      s2 += y;
      if(max<abs(s1-s2)){
          if(s2>s1)maxp=2;
          else maxp=1;
          max=abs(s2-s1);
      }
    }
    cout<<maxp<<" "<<max;
    return 0;
}