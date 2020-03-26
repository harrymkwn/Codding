#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define F(a, b, i) for (int i = a; i < b; i++)
#define f(a, b, i) for (int i = a; i >= b; i--)
#define m 1000000007

int total_cases(vector<int> val, int n,int w)
// {
//     if(w==0)return 1;
//     if(n<0 || w<0)return 0;

//     return total_cases(val,n,w-val[n]) + total_cases(val,n-1,w);
// }
{
    vector<vector<int>> dp(w+1,vector<int>(n+1,0));

    F(0,n,i)dp[0][i]=1;

    F(1,w+1,i){
        F(0,n+1,j){
            if(j>=1) dp[i][j] = dp[i][j-1];
            else if (i >= val[j])
            {
                dp[i][j]+= dp[i-val[j]][j];
            }
            
        }
    }
    return dp[w][n];

}
int main()
{
    vector<int> arr={2,3,5,6};
    int w=10;
    cout<<total_cases(arr,arr.size()-1,w);
    return 0;
}