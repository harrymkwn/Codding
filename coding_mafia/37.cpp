    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        int t;
        cin>>t;
        while(t--){
            int n;
            cin>>n;
            bool flag=true;
            if(n==1){cout<<"no\n";continue;}
            if(n%2==0 && n>2)flag=false;
            for(int i=3;i*i<=n && flag;i+=2){
                if(n%i==0)flag=false;
            }
            if(flag)cout<<"yes\n";
            else cout<<"no\n";
        }
        return 0;
    }