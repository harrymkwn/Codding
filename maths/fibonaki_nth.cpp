#include<iostream>
using namespace std;

void multiply(int A[2][2],int M[2][2]){
    int lvalue = A[0][0]*M[0][0] + A[0][1]*M[1][0];
    int svalue = A[0][0]*M[1][0] + A[0][1]*M[1][1];
    int tvalue = A[1][0]*M[0][0] + A[1][1]*M[1][0];
    int fvalue = A[1][0]*M[1][0] + A[1][1]*M[1][1];

    A[0][0]=lvalue;
    A[0][1]=svalue;
    A[1][0]=tvalue;
    A[1][1]=fvalue;
}

void getPower(int A[2][2],int n){

    if(n==0 || n==1)
        return;

    getPower(A,n/2);

    //Multiply A^n/2 with A^n/2
    multiply(A,A);

    if(n%2!=0){
        //Multiply A^n-1 with A
        int M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}


int getFibonacci(int n){

    int A[2][2]= {{1,1},{1,0}};
    getPower(A,n-1);

    return A[0][0];

}

int main(){
	int n;
	cin >> n;
	cout << getFibonacci(n)<<endl;
	return 0;
}