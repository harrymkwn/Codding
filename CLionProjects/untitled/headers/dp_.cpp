
// Created by harry on 24/5/19.
//
#include<bits/stdc++.h>
using  namespace std;
#include "dp_.h"

void dp_::fibonaki(int n) {
    int dp[n]={0};
    dp[0]=1;
    dp[1]=1;
    for (int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    cout<<dp[n-1];
}


void dp_::alph_code(char* arr,int n){
    if(arr[0]=='0')
        return;

    int* output = new int[n+1];
    output[0]=1;
    output[1]=1;

    for(int i=2;i<=n;i++){
        output[i] = output[i-1];
        if((arr[i-2]-48)*10+(arr[i-1]-48)<=26)
            output[i] +=output[i-2];
    }
    cout<<output[n];
}

void  dp_::lis(int *arr, int n,int** d) {
    int max=0;
    d[0][0]=1;
    int j;
    for(int i=1;i<n;i++){
        d[i][0]=1,max=1;
        for (j = i-1;  j>=0 ; j--) {
            if (arr[i] > arr[j] && d[j][0] + 1 > max)
                max = d[j][0] + 1;
        }
        d[i][0]=max;
    }
}

void dp_::lds(int*arr,int n,int** d){
    int max=0;
    d[n-1][1]=1;
    int j;
    for(int i=n-2;i>=0;i--){
        d[i][1]=1,max=1;
        for (j = i+1;j<n ; j++) {
            if (arr[i] > arr[j] && d[j][1] + 1 > max)
                max = d[j][1] + 1;
        }
        d[i][1]=max;
    }
}




//bitonicSubArray: largest sub array in that first values increasing mode and the decrassing
//takes argument as array and size of array
//retrun maximum size of bitonicSubArray
void dp_::bitonicsubarray(int *arr , int n){

    int max=0;
    int** output = new int*[n];
    for(int i=0;i<n;i++){
        output[i] = new int[2];
        output[i][0]=0,output[i][1]=0;
    }
    lis(arr,n,output);
    lds(arr,n,output);
    for(int i=0;i<n;i++)
        if(output[i][0]+output[i][1]>max)
            max=output[i][0]+output[i][1];

    cout<<max-1;
}


//minimum cost grid problem
// takes paramaeter as array of values and x and y index for which want minninnmum cost
//return minimum cost of that index
int dp_::minimumCost(int cells[][3],int n,int m){
    int dp[n][m] = {0};
    dp[0][0] = cells[0][0];

    for(int i=1;i<=m;i++)
        dp[0][i]=dp[0][i-1]+cells[0][i];
    for (int j = 0; j <=n ; ++j)
        dp[j][0]=dp[0][j-1]+cells[j][0];
    for (int i = 1 ; i <= n;i++)
        for(int j=1;j<=m;j++)
            dp[i][j] = cells[i][j] + min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));

    return dp[n][m];
}



//Fri=end pairing problem
//Takes number of friends and return total pairing without repititation of more than one friends
int dp_::friendPairing(int n){

    if(n<2)
        return n;
    else
    {       int dp[n+1]={0};
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + (i-1) * dp[i-2];
        }
        return dp[n];
    }
}

//subset sum find problem
//takes array of elements ,size and total sum which we have to do
//return if it is find
bool  dp_::ifthere(int a[],int n,int sum)
{
    bool dp[n+1][sum+1];

    for(int i=0 ;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=sum;i++)
        dp[0][i]= false;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=sum;j++){
            if(j<a[i-1])
                dp[i][j]=dp[i-1][j];
            if(j>=a[i-1])
                dp[i][j]= dp[i-1][j] || dp[i-1][j-a[i-1]];
        }
    return dp[n][sum];
}


//cutting rod problem
//in this problem we have to divide rod in that parts which give maximum profit
int dp_::cutrod(int arr[],int n){
    if(n<=0)
        return 0;
    int m=INT_MIN;
    for(int i=0;i<n;i++)
        m = max(m,arr[i]+cutrod(arr,n-1-i));

    return m;
}



//paint fence problem
//int this problem wh have to given number of paints and number of colours and we have to paint at most 2 adjacent fence with same colour
void dp_::paintFence(int n,int k)
{
    int dp[n+1]={0};
    dp[1]=k;
    int same=0,diff=k;
    for(int i=2;i<=n;i++){
        same = diff;
        diff = dp[i-1]*(k-1);
        dp[i]=same + diff;
    }
    cout<<dp[n];
}


//maximum sum rectangular submatrix in matrix

void dp_::khadane(int* arr , int n,int L , int R,dp_::maxValues & lastAns){

    int current_max_ending = 0,start=0,end=0;
    int best_so_far = 0;
    for(int i=0;i<n;i++){
        current_max_ending+=arr[i];
        if(best_so_far<current_max_ending){
            best_so_far=current_max_ending;
            end=i;
        }
        if(current_max_ending<0){
            current_max_ending=0;
            start=i+1;
        }
    }
    if(lastAns.maximumSum<best_so_far){
        lastAns.maximumSum=best_so_far;
        lastAns.maximumLeft=L;
        lastAns.maximumRight=R;
        lastAns.maximumUp=start;
        lastAns.maximumDown=end;
    }
}





void dp_::maximumSum(int grid[4][5],int n,int m){
    int L,R;
    dp_::maxValues lastAns;
    for(int L=0;L<m;L++){
        int arr[n]={0};
        for (int R = L; R < m; R++) {

            for(int i=0;i<n;i++)
                arr[i]+=grid[i][R];

            khadane(arr,n,L,R,lastAns);

        }
    }
    cout<<lastAns.maximumSum<<"\n"<<lastAns.maximumLeft<<"\n"<<lastAns.maximumRight<<"\n"<<lastAns.maximumUp<<"\n"<<lastAns.maximumDown;
}


//longest common sub sequence
int dp_::longestCommonSubsequence(string a,string b){
    int dp[a.size()+1][b.size()+1]={0};
    for (int i = 1; i <=a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    }
    return dp[a.size()][b.size()];
}


//among prises buy 2 times and ell 2 tiimes one after one
int dp_::maxProfit(int* price , int n){

    int* dp = new int[n];
    for(int i=0;i<n;i++)
    {
        dp[i]=0;
    }
    int max_price=price[n-1];
    for (int j =n-2; j >=0 ; j--) {
        if(max_price<price[j])
            max_price==price[j];


        dp[j]=max(dp[j+1],max_price-price[j]);
    }
    int min_price=price[0];
    for (int k = 1; k < n; k++) {
        if(min_price>price[k])
            min_price=price[k];

        dp[k] = max(dp[k-1],dp[k]+price[k]-min_price);
        cout<<dp[k]<<" ";
    }
    cout<<"\n";
    int result =   dp[n-1];
    delete[] dp;
    return result;
}

