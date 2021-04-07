#include<bits/stdc++.h>
using namespace std;

int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

    int maxv = INT_MAX,temp=INT_MAX,ind=0;

    for(int i=0;i<points.size();i++){
        if(x==points[i][0]){
            temp = abs(y - points[i][1]);
        }
        else if (y == points[i][1])
        {
            temp = abs(x - points[i][0]);
        }
        
        if(temp < maxv){maxv = temp;ind =i;}
    }        

    return maxv==INT_MAX ? -1 : ind;
}

int main(){
    
    return 0;
}