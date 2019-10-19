#include<bits/stdc++.h>
using namespace std;
#define n 16
static int c=0;
void printchess(int chess[n][n]){
for(int i=0;i<n;i++)
    for(int j=0;j<n;j++)
        cout<<chess[i][j];
}


bool safe(int chess[n][n],int row ,int col){

    for(int i=0;i<row;i++)
        if(chess[i][col]==1)
            return false;
    for(int i=row , j=col ; i>=0 && j>=0; i--,j--)
        if(chess[i][j])
            return false;

    for(int i=row , j=col ; i>=0 && j<n; i--,j++)
        if(chess[i][j])
            return false;

    return true;
}



void solve(int chess[n][n] , int row){
 if(row>=n)
{
printchess(chess);
c++;
cout<<endl;
}

for(int i=0;i<n;i++){
    if(safe(chess,row,i)){
        chess[row][i]=1;
        solve(chess,row+1);
        chess[row][i]=0;
}}}

void N_queen(){
int chess[n][n] = {0};
solve(chess,0);
}
int main(){
    N_queen();
    cout<<c;
    return 0;
}




