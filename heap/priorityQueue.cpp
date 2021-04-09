#include<bits/stdc++.h>
using namespace std;
template <typename T> ostream &operator<<(ostream &is, set<T> &s){cout<<"(";for (auto &ele : s)is << ele <<",";cout<<") "; return is;}

class PriorityQueue{

    //Declaration 
    int n,size;

    vector<int> queue;
    unordered_map<int, set<int>> lookup;

    int parent(int i){return (i-1)/2;}
    int left(int i){return 2*i+1;}
    int right(int i){return 2*i+2;}
    int neighbour(int i){return i%2==0 ? i-1 : i+1;}

    const void exchange(int i,int j){
        this->lookup[this->queue[i]].insert(j);
        this->lookup[this->queue[j]].insert(i);
        this->lookup[this->queue[i]].erase(i);
        this->lookup[this->queue[j]].erase(j);
        swap(this->queue[i],this->queue[j]);
    }

    void shiftingDown(int i){

        while(i<this->n){
            int l = left(i);
            int r = right(i);
            if(l<this->n && this->queue[i]>this->queue[l] && this->queue[l]<=(this->queue[r]==-1?INT_MAX : this->queue[r])){this->exchange(i,l); i=l;}
            else if(r<this->n && this->queue[i]>this->queue[r] && this->queue[l]>this->queue[r]){this->exchange(i,r);i=r;}
            else break;
            this->print();
        }
    }
    void shiftingUp(int i){

        while(i>=0 && queue[i]<queue[parent(i)]){
            this->exchange(i,parent(i)); 
            i=parent(i);
        }
    }

    void insert(int x){
        if(this->n == this->size){
            this->size *= 2;
            this->queue.resize(this->size);
        }
        this->queue[this->n] = x;
        this->lookup[x].insert(this->n);
        this->shiftingUp(this->n);

        this->n++;
    }

    /***
     *  Funtion removes head of priority queue and return value
     *  If there is no element in priority queue than it returns -1 
     */

    void poll(){
        if(this->n==0){cout<<"Priority Queue is Empty ";return;}
        int returnValue = this->queue[0];
        this->lookup[returnValue].erase(0);
        this->queue[0] = this->queue[this->n-1];
        this->queue[this->n-1]=-1;
        this->lookup[this->queue[0]].erase(this->n-1);
        this->lookup[this->queue[0]].insert(0);
        this->n--;
        this->shiftingDown(0);
    }

    void remove(int x){
        if(this->lookup[x].size()==0){cout<<"There is no element with value "<<x<<".";}

        int exchangei= *this->lookup[x].begin();
        this->lookup[x].erase(exchangei);
        this->queue[exchangei] = this->queue[this->n-1];
        this->queue[this->n-1]=-1;
        this->lookup[this->queue[exchangei]].erase(this->n-1);
        this->lookup[this->queue[exchangei]].insert(exchangei);
        this->n--;
        this->shiftingDown(exchangei);
    }

    public: 

    PriorityQueue(vector<int> array){
        this->n = array.size();
        int h = (int)ceil(log2(this->n));
        this->size = 2*pow(2,h);
        this->queue.resize(this->size,-1);

        for(int i=0;i<this->n;i++)this->insert(array[i]);
    }

    PriorityQueue(){
        this->n = 0;
        this->size = 1;
        this->queue.resize(this->size,-1);
    }

    void push(int x){
        this->insert(x);
    }

    int top(){
        return this->queue[0];
    }

    void pop(){
        this->poll();
    }

    void pop(int x){
        this->remove(x);
    }

    void print(){
        int b=1;
        cout<<"\n\n";
        for(int i=0;i<this->n;i++){
            cout<<this->queue[i]<<" ";
            cout<<this->lookup[this->queue[i]];
        }

    }
};




int main(){
    return 0; 
}