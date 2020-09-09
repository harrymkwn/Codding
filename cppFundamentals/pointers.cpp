#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007


void foo(int *&ptr){

    ptr = new int(7);
    cout<<"in foo : "<<*ptr<<"\n";
}

int main(){
  
  int a = 6;

  int * ptr = &a;

  cout<<"before called : "<<*ptr<<"\n";

  foo(ptr);

  cout<<"after called : "<<*ptr<<"\n";
  return 0;
}