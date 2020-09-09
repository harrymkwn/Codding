
#include<bits/stdc++.h>
using namespace std;
bool out_of_matrix(int i,int j,int n){
    return  i>=0 && j>=0 && i<n && j<n;
}

void abc_helper(char* matrix[][],int n,int i,int j, string str ,char dir,int ind,bool &flag){
    if(ind==str.size()){flag = true; return;}


    if(!out_of_matrix(i,j,n),str[ind]==matrix[i][j]){
        if(dir=='r'){
        abc_helper(matrix,n,i+1,j,str,dir,ind+1,flag);
        if(flag)return ;
        }
        if(dir=='d'){
        abc_helper(matrix,n,i,j+1,str,dir,ind+1,flag);
        if(flag)return ;
        }
    }
    return;
}

bool abc(char**matrix[][],int n,string str){
    bool flag=false;
    int ind=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(str[0]==matrix[i][j]){
                abc_helper(matrix,n,i+1,j,str,'d',ind+1,flag);
                if(flag)return true;
                abc_helper(matrix,n,i,j+1,str,'r',ind+1,flag);
                if(flag)return true;
            }
        }
    }
    return flag;
}