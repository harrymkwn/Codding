#include<bits/stdc++.h>
using namespace std;

int dp[10000][50000]={0};
struct node
{
    int cap,ass;
    node(){cap=0;ass=0;}
};

// minimum pay without any condition
// int minpaying(node* arr,int n,int c,int a){

//     if(c==0 && a==0)
//         return 0;
//     else if(c==0 && a>0)
//         return arr[n].ass + minpaying(arr,n-1,c,a-1);
//     else if (a==0 && c>0)
//         return arr[n].cap + minpaying(arr,n-1,c-1,a);
//     else{
//         return min(arr[n].cap + minpaying(arr,n-1,c-1,a),arr[n].ass + minpaying(arr,n-1,c,a-1));
//     }

    
    
// }

int minpaying(node* arr,int n,int x){
    if(n>0){
    if(x==0){
        if(!dp[n-1][1])
            dp[n-1][1] = minpaying(arr+1,n-1,1);
        return arr[0].ass + dp[n-1][1];
    }
    else if (x==n){
        if(!dp[n-1][x-1])
            dp[n-1][x-1] = minpaying(arr+1,n-1,x-1);
        return arr[0].cap + dp[n-1][x-1];
    }
    else
    {
        if(!dp[n-1][x+1])
            dp[n-1][x+1] = minpaying(arr+1,n-1,x+1);
        if(!dp[n-1][x-1])
            dp[n-1][x-1] =  minpaying(arr+1,n-1,x-1);
        return min(arr[0].ass + dp[n-1][x+1],arr[0].cap + dp[n-1][x-1]);
    }    
    }
}

int main(){
    int n;
    cin>>n;
    node * arr = new node[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].cap>>arr[i].ass;
    }

    cout<<minpaying(arr,n,0);


}




