#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

string caesarCypherEncryptor(string str, int key) {
  
  for (int i = 0; i < str.size(); i++)
  {
      str[i] = (str[i] - 97 + key)%26 + 97;
  }
  
  return str;
}

int main(){
  
  string str = "xyz";
  int key = 2;

  cout<<caesarCypherEncryptor(str,key);
  return 0;
}