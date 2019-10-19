#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
void alph_code(string arr,int n){
    long long* output = new long long[n+1];
    output[0]=1;
    output[1]=1;
    
    for(int i=2;i<=n;i++){
        if(arr[i-1]!='0')
        output[i] = output[i-1]%mod;
        else
        output[i]=0;
        
        if((arr[i-2]-48)*10+(arr[i-1]-48)<=26 && (arr[i-2]-48)*10+(arr[i-1]-48)>=10)
            output[i] +=output[i-2]%mod;
        output[i]=output[i]%mod;
    }
    cout<<output[n]%mod<<"\n";
    delete [] output;
}


int main(){
    char str[5000];

    while (scanf("%s", str) > 0) {
        alph_code(str,strlen(str));  
    }
return 0;
}

