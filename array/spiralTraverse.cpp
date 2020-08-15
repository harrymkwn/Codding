#include<bits/stdc++.h>
using namespace std;


vector<int> spiralTraverse(vector<vector<int>> arr){
    int i=0,j=0;
    bool flag = false;
    vector<int> ret;
    ret.push_back(arr[0][0]);
    while (true)
    {
        if(i==arr.size()-1 && j==0){flag = true; j++; ret.push_back(arr[i][j]);}
        else if(i==0 && j==arr[0].size()-1){flag = false; i++; ret.push_back(arr[i][j]);}
        else if(j==0){flag = true; i++; ret.push_back(arr[i][j]);}
        else if(i==0){flag = false; j++; ret.push_back(arr[i][j]);}
        else if(i==arr.size()-1){flag = true; j++; ret.push_back(arr[i][j]);}
        else if(j==arr[0].size()-1){flag = false; i++; ret.push_back(arr[i][j]);}
        
        if(i== arr.size() -1 && j ==arr[0].size() - 1)break;
        
        if(flag){i--;j++;}
        else{j--;i++;}
        ret.push_back(arr[i][j]);
    }
    return ret;
}

int main(){
    vector<vector<int>> arr = {
        {1,3,4},
        {2,5,8},
        {6,7,9}
    };

    vector<int> ret = spiralTraverse(arr);

    for(int i=0;i<ret.size();i++)cout<<ret[i]<<" ";
    return 0;
}