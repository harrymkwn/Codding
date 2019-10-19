#include<bits/stdc++.h>
using namespace std;

void print(int a[3][3],int n){
cout<<endl<<n<<endl;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
cout<<a[i][j]<<" ";
cout<< endl;
}
}


void dynamic(int** a ,int n,string s){
cout<<endl<<n<<s<<endl;
for(int i=0;i<3;i++){
for(int j=0;j<3;j++)
cout<<a[i][j]<<" ";
cout<< endl;
}
}

void doublechange(int a[3][3],int** b,int c){
cout<<c<<endl;
c=15;
cout<<c<<endl;

a[1][1]=10;
b[1][1]=10;
print(a,2);
dynamic(b,1,"dynamic");
}

void change(int a[3][3],int** b,int c){
cout<<c<<endl;
c=10;
cout<<c<<endl;
a[0][2]=0;
b[0][2]=0;
print (a,1);
dynamic(b,1,"dynamic");
doublechange(a,b,c);
cout<<c<<endl;
dynamic(b,3,"dynamic");
print(a,3);
}


int main(){

    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int** b = new int*[3];
    for(int i=0;i<3;i++){
        b[i] = new int[3];
        for(int j=0;j<3;j++)
        b[i][j]=i*3+j+1;
    }

    int c=5;
    cout<<c<<endl;
    dynamic(b,0,"dynamic");
    change(a,b,c);
    print(a,4);
    dynamic(b,4,"dynamic");
    cout<<c<<endl;
}
