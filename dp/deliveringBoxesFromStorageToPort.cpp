#include<bits/stdc++.h>
using namespace std;

int boxDelivering(vector<vector<int>>& boxes, int portsCount, int maxBoxes, int maxWeight) {

    int n=boxes.size();
    vector<int> dp(n+1);
    int cost=1,w=0,j=0;
    for(int i=0;i<n;i++){

        if(i==0 || boxes[i][0] != boxes[i-1][0])cost +=1;
        w += boxes[i][1];

        while (i-j+1 > maxBoxes || w > maxWeight || (j<i && dp[i]==dp[j]))
        {
            w -= boxes[j][1];

            if(boxes[j][0]==boxes[j-1][0])cost-=1;

            j++;
        }
        dp[i+1] = dp[j] + cost;
    }

    return dp[n];

}

int main(){
    
    return 0;
}