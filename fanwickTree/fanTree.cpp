#include<bits/stdc++.h>
using namespace std;

class FanwickTree
{
    int n;
    vector<int> tree,array;
    
    int lsb(int x){
        return (x & -x);
    }

    void buildTree(){

        for(int i=1;i<=n;i++){
            this->tree[i] += this->array[i-1];

            int j = i + lsb(i);
            if(j<=this->n)
                this->tree[j] += this->tree[i];
        }
    }

public:
    FanwickTree(vector<int> &arr){
        this->n = arr.size();
        this->array = arr;
        this->tree.resize(n+1,0);
        this->buildTree();
    }

    FanwickTree(int n){
        this->n = n;
        this->tree.resize(n+1,0);
    }

    void update(int index){
        int i = index + 1;

        while(i<=this->n){
            this->tree[i] += this->array[index];
            i += lsb(i);
        }
    }

    int query(int upto){
        int i = upto;
        int count = 0;
        while(i>0){
            count += this->tree[i];
            i -= lsb(i);
        }
        return count;
    }

    void print(){
        for(auto x : this->tree)cout<<x<<" ";
        cout<<"\n";
    }
};

int main(){

    vector<int> arr({1,2,3,4,5,6,7,8,9,10});
    FanwickTree tree(arr);

    tree.print();
    cout<<tree.query(8)<<"\n";
    return 0;
}