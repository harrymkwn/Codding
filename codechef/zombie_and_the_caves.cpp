#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t=0;
    cin>>t;
    int n;
    while (t--) {
        cin >> n;
        int rad[n] = {0}, hel[n] = {0};
        for (int i = 0; i < n; i++)cin >> rad[i];
        for (int i = 0; i < n; i++)cin >> hel[i];

        int prefix[n] = {0};
        for (int i = 0; i < n; i++) {
            if (i - rad[i] < 0)
                prefix[0]++;
            else prefix[i - rad[i]]++;

            if (i + rad[i] +1< n)prefix[i + rad[i] + 1]--;
        }
        for(int i=1;i<n;i++)prefix[i] = prefix[i-1] + prefix[i];
        bool flag = true;
        map<int,int>hash;
        for(int i=0;i<n;i++){
            hash[prefix[i]-1]++;
            hash[hel[i]-1]--;
        }
        map<int,int>:: iterator itr=hash.begin();
        for(itr;itr!=hash.end();itr++){
            if(itr->second!=0){
                flag= false;
                break;
            }
        }

        if(flag)cout<<"YES\n";
        else cout<<"NO\n";
    }
}