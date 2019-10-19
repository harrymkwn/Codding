// #include<bits/stdc++.h>
// using namespace std;
// #define n 16
// static int c=0;
// void printchess(int chess[n][n]){
// for(int i=0;i<n;i++)
//     for(int j=0;j<n;j++)
//         cout<<chess[i][j];
// }


// bool safe(int chess[n][n],int row ,int col){

//     for(int i=0;i<row;i++)
//         if(chess[i][col]==1)
//             return false;
//     for(int i=row , j=col ; i>=0 && j>=0; i--,j--)
//         if(chess[i][j])
//             return false;

//     for(int i=row , j=col ; i>=0 && j<n; i--,j++)
//         if(chess[i][j])
//             return false;

//     return true;
// }



// void solve(int chess[n][n] , int row){
//  if(row>=n)
// {
// printchess(chess);
// c++;
// cout<<endl;
// }

// for(int i=0;i<n;i++){
//     if(safe(chess,row,i)){
//         chess[row][i]=1;
//         solve(chess,row+1);
//         chess[row][i]=0;
// }}}

// void N_queen(){
// int chess[n][n] = {0};
// solve(chess,0);
// }
// int main(){
//     N_queen();
//     cout<<c;
//     return 0;
// }




#include<bits/stdc++.h>
using namespace std;

void paste(int** print,int n){
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cout<<print[i][j]<<" ";
}



bool check(int maze[][20],int n,int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1)
        return true;
    return false;
}


bool find(int maze[][20],int n,int** print , int x, int y)
{

    if(x==n-1 && y==n-1){
        print[x][y]=1;
        paste(print,n);
        cout<<endl;
        return true;
    }

    if(check(maze,n,x,y)==true){

        print[x][y]=1;


        if(find(maze,n,print,x+1,y)==true);
            return true;
        if(find(maze,n,print,x,y+1)==true);
            return true;

        print[x][y]=0;
        return false;
    }
    return false;

}




void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int ** print = new int*[n];
    for(int i=0;i<n;i++){
        print[i] = new int[n];
        for(int j=0;j<n;j++)
            print[i][j]=0;
        }

    find(maze,n,print,0,0);


}

