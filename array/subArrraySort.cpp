#include<bits/stdc++.h>
using namespace std;

vector<int> subarraySort(vector<int> array) {
  if(array.size()<2)return {-1,-1};
  if(array.size()==2 && array[0] < array[1]) return {-1,-1};

  int i = 0;
  int j = array.size()-1;

  while(i<=j && array[i] < array[i+1])i++;
  while(i<=j && array[j] > array[j-1])j--;
  if(i>=j)return {-1,-1};
    int max = INT_MIN;
    int min = INT_MAX;

    for(int k=i;k<=j;k++){
        if(array[k]>max)max = array[k];
        if(array[k]<min)min = array[k];
    }
    cout<<i<<" "<<j<<"\n";;
    cout<<min<<" "<<max<<"\n";;

    while (true)
    {
        bool flag = true;
        if(array[i] > min)
        {
            if(i!=0 && array[i]>max)max=array[i];
            i--;
            flag=false;
        }
        if(j!=array.size() && array[j] < max){
            if(array[j] < min)min = array[j];
            j++;
            flag = false;
        }
        if(flag)return {i+1,j-1};
    }
}


int main(){
    vector<int> ret  = subarraySort({1, 2, 8, 4, 5});
    cout<<ret[0]<<" "<<ret[1]<<"\n";
    return 0;
}