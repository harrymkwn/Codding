#include<bits/stdc++.h>
using namespace std;

class queue1{
    deque<int> q;
    
    public:

    int minimum(){
        if(q.empty())return -1;
        return q.front();
    }

    void add(int x){
        while(!q.empty() && x < q.back()){
            q.pop_back();
        }
        q.push_back(x);
    }

    void remove(int remove_element){
        if(!q.empty() && q.front()==remove_element)q.pop_front();
    }
};

class queue2{
    deque<pair<int,int>> q;
    int c_add=0,c_remove=0;
    
    public:

    int minimum(){
        if(q.empty())return -1;
        return q.front().first;
    }

    void add(int x){
        while(!q.empty() && x < q.back().first){
            q.pop_back();
        }
        q.push_back({x,c_add});
        this->c_add++;
    }

    void remove(int remove_element){
        if(!q.empty() && q.front().second == remove_element)q.pop_front();
        this->c_remove++;
    }
};


// adding to this->s1 and removing from this->s2

class queue3{
    stack<pair<int,int>> s1,s2;
    
    public:

    int minimum(){
        int minimum=-1;
        if(this->s1.empty() || this->s2.empty()){
            minimum = this->s1.empty() ? this->s2.top().second : this->s1.top().second ;
        }
        else{
            minimum = min(this->s1.top().first , this->s2.top().first);
        }
        return minimum;
    }

    void add(int x){
        int minimum= this->s1.empty() ? x : min(x,this->s1.top().second);
        this->s1.push({x,minimum});
    }

    void adjust(){

        int minimum;
        while(!this->s1.empty()){
            int ele = this->s1.top().first;
            this->s1.pop();
            minimum = this->s2.empty() ? ele : min(ele, this->s2.top().second);
            this->s2.push({ele,minimum});
        }
    }

    int remove(int remove_element){
        if(this->s2.empty())this->adjust();
        int ret = this->s2.top().first;
        this->s2.pop();
        return ret;
    }
};

int main(){
    vector<int> arr({33,11,44,11,55});
    queue1 q;
    for(int i=0;i<5;i++){
        q.add(arr[i]);
        cout<<q.minimum()<<endl;
    }
    return 0;
}