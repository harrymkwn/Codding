#include<bits/stdc++.h>
using namespace std;



//This solution is right but gets tle because updation and sorting
class Solution {

    int n,size;
    vector<int> tree;

    bool static compareVector(vector<int> a,vector<int> b){
        if(a[1]!=b[1])return a[1]<b[1];

        return a[0]<b[0];
    }
    int find_max(vector<vector<int>> events){
        return events.back()[1];
    }

    void update(int start,int end,int l,int r,int in,bool &sharedVar){
        if(sharedVar || end < l || r < start || in >= size)return;
        if(start==end){
            if(tree[in]==1)return;

            tree[in]=1;
            sharedVar=true;
            return; 
        }

        int mid = (start + end)/2;
        update(start,mid,l,r,2 * in, sharedVar);
        update(mid+1,end,l,r,2 * in +1,sharedVar);
        tree[in] = tree[2*in] + tree[2*in + 1];
    }



public:
    int maxEvents(vector<vector<int>>& events) {
        n = events.size();
        if(n==1 || n==0)return n;
        if(!is_sorted(events.begin(),events.end(),compareVector))
            sort(events.begin(),events.end(),compareVector);

        int max = find_max(events);
        int h = (int)ceil(log2(max));
        size = 2*pow(2,h);
        tree.resize(size+1,0);
        for(auto x: events){
            bool sharedVar = false;
            update(0,max-1,x[0]-1,x[1]-1,1,sharedVar);
        }
        return tree[1];
    }
    
};

int maxEvents(vector<vector<int>>& events) {

    priority_queue<int,vector<int>,greater<int>> pq;
    sort(events.begin(),events.end());

    int i=0,ret=0,n=events.size();
    for(int j=1;j<=100000;j++){
        while (!pq.empty() && pq.top()<j)
            pq.pop();

        while (i<n && events[i][0]==j)
            pq.push(events[i++][1]);

        if(!pq.empty()){
            pq.pop();
            ret++;
        }
    }    

    return ret;    
}




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
