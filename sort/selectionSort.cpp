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

vector<int> selectionSort(vector<int> array) {

    for(int i=0;i<array.size();i++){
        int max = INT_MIN,mi=0;
        for(int j=0;j<array.size()-i;j++){
            if(max < array[j]){
                mi = j;
            }
        }
        change(&array[mi],&array[array.size()-i]);
    }
  return array;
}
int main(){
  
  return 0;
}