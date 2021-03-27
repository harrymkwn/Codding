#include<bits/stdc++.h>
using namespace std;

class Solution {

    int n,size;
    vector<int> tree;

    bool static compareVector(vector<int> a,vector<int> b){
        if(a[0]!=b[0])return a[0]<b[0];

        return a[1]<b[1];
    }

    int find_max(vector<vector<int>> events){

        int ret=0;
        for(auto x: events)
            if(ret < x[1])ret = x[1];

        return ret;
    }

    void update(int start,int end,int l,int r,int in,bool &sharedVar){
        if(sharedVar || end < l || r < start || in >= size)return;
        if(start==end){
            if(tree[in]==1)return;

            tree[in]=1;
            cout<<start<<" "<<in<<"\n";
            sharedVar=true;
            return; 
        }

        cout<<start<<" "<<end<<" "<<in<<"\n";
        int mid = (start + end)/2;
        update(start,mid,l,r,2 * in, sharedVar);
        update(mid+1,end,l,r,2 * in +1,sharedVar);
        tree[in] = tree[2*in] + tree[2*in + 1];
    }



public:
    int maxEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(),events.end(),compareVector);

        int max = find_max(events);
        int h = (int)ceil(log2(max));
        size = pow(2,h+1);
        tree.resize(size,0);
        for(auto x: events){
            bool sharedVar = false;
            cout<<x[0]<<x[1]<<"\n";
            update(0,n-1,x[0]-1,x[1]-1,1,sharedVar);
            cout<<"\n";
        }
        print_tree();
        return tree[1];
        // return 0;
    }
    
};


int main(){
    int _n;
    cin>>_n;
    vector<vector<int>> arr(_n,vector<int>(2,0));
    for(auto &x : arr){
        cin>>x[0]>>x[1];
    }
    for(auto x:arr)cout<<x[0]<<x[1]<<"\n";

    Solution obj;
    int x = obj.maxEvents(arr);
    // obj.print_tree();
    // cout<<x<<"\n";
    return 0;
}
