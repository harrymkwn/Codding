#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
public:
    vector<int> heap;

    int heapSize;
    int capacity;
    MinHeap(vector<int> vector) {heap =  buildHeap(vector); }

    int parent(int k){ return k/2; }
    int leftChild(int k){ return k*2; }
    int rightChild(int k){ return (k*2 + 1); }

    vector<int> buildHeap(vector<int> &vector)
    {
        heapSize = 1;
        capacity = pow(2,log2(vector.size())+1);
        heap.resize(capacity,0);
        for(int i=0;i<vector.size();i++){
            insertTOHeap(vector[i]);
        }
        return heap;
    }

    void heapify(int k){
        int l = leftChild(k);
        int r = rightChild(k);
        int changed = k;
        if(l<heapSize && heap[l]<heap[changed])
            changed = l;
        if(r<heapSize && heap[r]<heap[changed])
            changed = r;
        if(changed !=k){
            swap(heap[changed],heap[k]);
            heapify(changed);
        }
    }

    void insertTOHeap(int val){
        if(heapSize==capacity){
            cout<<"heap is overflow so you can`t insert\n";
            return;
        }
        int i= heapSize;
        heapSize++;
        heap[i] = val;

        while (i!=1 && heap[parent(i)] >  heap[i])
        {
            swap(heap[parent(i)],heap[i]);
            i = parent(i);
        }
    }

    void modify(){
        if(heapSize <=1)return;
        if(heapSize == 2)return;

        heap[1] = heap[(heapSize-1)];
        heapSize--;
        heapify(1);
    }
    void decrease(int i, int newValue){
        heap[i] = newValue;
        while(i!=1 && heap[i] < heap[parent(i)])
        {
            swap(heap[i],heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteFormHeap(int i){
        decrease(i,INT_MIN);
        modify();
    }


    void display(){
        int i=1;
        for(int j=1;j<this->heapSize;j++){
            if(i==j){
                cout<<"\n";
                i*=2;
            }
            cout<<heap[j]<<" ";
        }
    }


    void siftDown(int currentIdx, int endIdx, vector<int> &heap)
    {
        
    }

    void siftUp(int currentIdx, vector<int> &heap)
    {
        
    }

    int peek()
    {
        if(heapSize==1)
            return -1;
        return heap[1];
    }

    int remove()
    {
        if(heapSize==1)return -1;
        int ret = peek();
        deleteFormHeap(1);
        return ret;
    }

    void insert(int value)
    {
        insertTOHeap(value);
    }
};


int main(){
    MinHeap h({9,8,7,6,5,4,3,2,1});
    cout<<h.peek()<<"\n";
    cout<<h.remove()<<"\n";
    h.display();
    return 0;
}