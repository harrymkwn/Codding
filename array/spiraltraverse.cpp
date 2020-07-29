#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

vector<int> spiralTraverse(vector<vector<int>> array) {
  
	int i=0;
	vector<int> ret;
    int m = array.size();
    int n = array[0].size();
	while(true){
		for(int k=i;k<array[0].size();k++)
            ret.push_back(array[i][k]);
		
		for(int k=i+1;k<array.size();k++){
            ret.push_back(array[k][n-i]);
        }

        for(int k=n-i-1;k>=0;k--){
            ret.push_back(array[m-i][k]);
        }
	}
  return {};
}

int main(){
  
  return 0;
}