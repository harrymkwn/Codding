#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

void change(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

vector<int> insertionSort(vector<int> array) {
  
  if(array.size()<2)return array;
  for(int i=1;i<array.size();i++){
      int j=i;
      while(j>0 && array[j]<array[j-1]){
          change(&array[j],&array[j-1]);
          j++;
      }
  }
  return array;
}

int main(){
  
  return 0;
}