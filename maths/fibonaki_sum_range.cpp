#include<iostream>
using namespace std;
#define mod 1000000007
void multiply(long long A[2][2],long long M[2][2]){
    long long lvalue = A[0][0]*M[0][0] + A[0][1]*M[1][0];
    long long svalue = A[0][0]*M[1][0] + A[0][1]*M[1][1];
    long long tvalue = A[1][0]*M[0][0] + A[1][1]*M[1][0];
    long long fvalue = A[1][0]*M[1][0] + A[1][1]*M[1][1];

    A[0][0]=lvalue%mod;
    A[0][1]=svalue%mod;
    A[1][0]=tvalue%mod;
    A[1][1]=fvalue%mod;
}

void getPower(long long A[2][2],long long n){

    if(n==0 || n==1)
        return;

    getPower(A,n/2);
    multiply(A,A);

    if(n%2!=0){
        long long M[2][2]={{1,1},{1,0}};
        multiply(A,M);
    }
}


long long getFibonacci(long long n){

    long long A[2][2]= {{1,1},{1,0}};
    getPower(A,n-1);

    return A[0][0]%mod;

}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	return (unsigned long long)((getFibonacci(n+2)-getFibonacci(m+1) + mod)%mod);
}

