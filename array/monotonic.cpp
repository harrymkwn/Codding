#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

bool isMonotonic(vector<int> array) {
  bool flag = array[0] < array[1];
	
	for(int i=1;i<array.size();i++){
		if(flag && array[i]<array[i-1]){
			return false;
		}else if(!flag && array[i]>array[i-1]){
			return false;
		}
	}
  return true;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr(n,0);
    for(int i=0;i<n;i++)cin>>arr[i];
  if(isMonotonic(arr))
    cout<<"yes";
    else cout<<"No";
  return 0;
}