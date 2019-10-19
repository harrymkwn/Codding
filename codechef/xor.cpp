







#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t=0;
    cin>>t;
    int n;
    while (t--) {
        cin>>n;
        int a[n] ={0};
        int prexor[n]={0};
        map<int , vector<pair<int,int>>> mp;
        for(int i=0;i<n;i++)cin>>a[i];

        prexor[0]=a[0];
        //cout<<a[0]<<" ";
        mp[prexor[0]].emplace_back(0,0);
        for(int i=1;i<n;i++){
            prexor[i] = prexor[i-1]^a[i];
            mp[prexor[i]].emplace_back(make_pair(0,i));
            //cout<<prexor[i]<<" ";
        }
        //cout<<"\n";
        int b=0;
        for(int i=1;i<n;i++){
            for(int j=i;j<n;j++){
                b = prexor[i-1]^prexor[j];
                //cout<<b<<" ";
                mp[b].emplace_back(make_pair(i,j));
            }
            //cout<<"\n";
        }
        map<int , vector<pair<int,int>>>::iterator itr;
//        for(auto itr=mp.begin(); itr!=mp.end();itr++){
//            //cout<<itr->first<<"\n";
//            for(int i=0;i<itr->second.size();i++){
//                cout<<itr->second[i].first<<" "<<itr->second[i].second<<"\n";
//            }
//        }
        int count =0;
        for(auto itr=mp.begin();itr!=mp.end();itr++){
            for(int i=0;i<itr->second.size();i++){
                for(int j=i+1;j<itr->second.size();j++){
                    if(itr->second[i].second = itr->second[j].first - 1) {
                        count++;
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
