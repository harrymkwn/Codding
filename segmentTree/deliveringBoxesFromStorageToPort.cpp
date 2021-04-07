#include<bits/stdc++.h>
using namespace std;

int boxDeliveringUtils(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight,int i){

    if(i>=boxes.size())return 0;

    vector<int> a;
    int temp=1,j=0,currentWeight=0,prevPort=-1;

    while (currentWeight+boxes[i+j][1] <=maxWeight && j+1<=maxBoxes && (i+j+1)<boxes.size())
    {
        temp += boxDeliveringUtils(boxes,portsCount,maxBoxes,maxWeight,i+j+1) + (prevPort==boxes[i+j][0] ? 0 : 1);
        currentWeight += boxes[i+j][1];

        a.push_back(temp);
        prevPort = boxes[i+j][0]; 
        j++;
    }

    return *min_element(a.begin(),a.end());
}

int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {
    return boxDeliveringUtils(boxes,portsCount,maxBoxes,maxWeight,0);        
}

int main(){
    
    return 0;
}