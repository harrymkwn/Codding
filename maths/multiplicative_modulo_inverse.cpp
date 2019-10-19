#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
        int x;
        int y;
        int gcd;
};

Triplet extendedEuclid(int a,int b){

    if(b==0){
        Triplet ans;
        ans.gcd = a;
        ans.x = 1;
        ans.y = 0;
        return ans;
    }

    Triplet smallans = extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd = smallans.gcd;
    ans.x = smallans.y;
    ans.y = smallans.x - (a/b)*smallans.y;
    return ans;
}

int mmInverse(int a,int m){
    Triplet ans = extendedEuclid(a,m);
    return ans.x;
}
int main(){
    int a=25;
    int m=36;
    int ans  = mmInverse(a,m);
    cout<<ans<<"\n";
}