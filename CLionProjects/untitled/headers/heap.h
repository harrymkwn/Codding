//
// Created by harry on 19/6/19.
//

#ifndef UNTITLED_HEAP_H
#define UNTITLED_HEAP_H


class heap_ {

private:

    int heap_size;
    int *heap;
    int capacity;
public:
    heap_(int k);
    void swap(int *a,int *b){  int c = *a; *a=*b; *b=c;}
    int parent(int i){ return  (i-1)/2;}

    int left(int i){return 2*i+1;}
    int right(int i){ return 2*i+2;}

    void insert(int n);
    void heapify(int i);
    void delet(int i);
    void decrease(int i,int new_value);
    void modify();
    void display();
    void heapsort();
    void heapifyn(int i,int n);
    bool isheap(int*arr,int n,int k);

};


#endif //UNTITLED_HEAP_H
