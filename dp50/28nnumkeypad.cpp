#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char>> grid,int i,int j){
    return (i>=0 && j>=0 && i<4 && j<3 && grid[i][j]!='*' && grid[i][j]!='#');
}

void countpossible(vector<vector<char>> grid,int n,int &tot,int i,int j){

    if(!isValid(grid,i,j))return;
    if(n==0){tot++;return;}

    countpossible(grid,n-1,tot,i-1,j);
    countpossible(grid,n-1,tot,i,j-1);
    countpossible(grid,n-1,tot,i+1,j);
    countpossible(grid,n-1,tot,i,j+1);

}

int main(){
    vector<vector<char>> grid({{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}});
    // vector<vector<bool>> isvisited(4,vector<bool>(4,false))
    int n,tot=0;
    cin>>n;
    for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
        countpossible(grid,n,tot,i,j);

    cout<<tot<<"\n";
    return 0;
}