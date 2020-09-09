// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.
// Input: 5
// Output:
// [
// [1],
// [1,1],
// [1,2,1],
// [1,3,3,1],
// [1,4,6,4,1]
// ]
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> pascle_triangle(int n){
    vector<vector<int>> ret(n,vector<int>());
    ret[0].push_back(1);
    ret[1].push_back(1);
    ret[1].push_back(1);
    for(int i=2;i<n;i++){
        ret[i].push_back(1);
        for(int j=0;j<ret[i-1].size()-1;j++){
            ret[i].push_back(ret[i-1][j]+ ret[i-1][j+1]);
        }
        ret[i].push_back(1);
    }
    return ret;
}
int main(){
    int n = 10;
    vector<vector<int>> ret  = pascle_triangle(n) ;
    for(int i=0;i<ret.size();i++){
        for(int j=0;j<ret[i].size();j++)cout<<ret[i][j]<<" ";
        cout<<"\n";
    }
}

// Write an SQL query to fetch duplicate records having matching data in some fields of a table.
// Employee_id,name ,dob
 
select employee_id from (select name,dob from table where )

select id from table whose salary in (select)
