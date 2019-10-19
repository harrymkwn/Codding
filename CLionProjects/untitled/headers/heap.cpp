//
// Created by harry on 19/6/19.
//

#include "heap.h"
#include <bits/stdc++.h>
using namespace std;

heap_::heap_(int k) {
    heap_size=0;
    heap = new int[k];
    capacity = k;
}

void heap_::insert(int n) {
    if(heap_size==capacity)
        printf("heap is overflow, so you can`t insert key ");

    int i=heap_size;
    heap_size++;
    heap[i]=n;

    while (i!=0 && heap[parent(i)]>heap[i]){
        heap_::swap(&heap[parent(i)],&heap[i]);
        i=parent(i);
    }
}

void heap_::heapify(int i) {
    int l=heap_::left(i);
    int r=heap_::right(i);
    int changed=i;
    if(l<heap_size && heap[l]<heap[i])
        changed=l;
    if(r<heap_size && heap[r]<heap[changed])
        changed=r;

    if(changed != i)
    {
        swap(&heap[changed],&heap[i]);
        heapify(changed);
    }
}
void heap_::modify() {
    if(heap_size<=0)
        return ;
    if(heap_size==1)
        return;
    heap[0]=heap[(heap_size)-1];
    heap_size--;
    heap_::heapify(0);

}


void heap_::decrease(int i, int new_value) {
    heap[i]=new_value;
    while (i<heap_size && heap[i]<heap[parent(i)])
    {
        swap(&heap[i],&heap[parent(i)]);
        i=parent(i);
    }
}
void heap_::delet(int i) {
    decrease(i,INT_MIN);
    modify();
}



void heap_::display() {
    int twos=2;
    for(int i=0;i<heap_size;i++)
    {
        cout<<heap[i]<<" ";
        if(twos-2==i)
        {
            twos*=2;
            cout<<"\n";
        }
    }
    cout<<"\n\n";
}

void heap_::heapifyn(int i,int n) {
    int l=heap_::left(i);
    int r=heap_::right(i);
    int changed=i;
    if(l<=n && heap[l]<heap[i])
        changed=l;
    if(r<=n && heap[r]<heap[changed])
        changed=r;

    if(changed != i)
    {
        swap(&heap[changed],&heap[i]);
        heapifyn(changed,n);
    }
}


void heap_::heapsort() {
    heapifyn(0,heap_size-1);
    for(int i=heap_size-1;i>=0;i--)
    {
        swap(&heap[0],&heap[i]);
        heapifyn(0,i-1);
    }

    reverse(heap,heap+heap_size);
    for(int i=0;i<heap_size;i++)
        cout<<heap[i]<<" ";
}

//pass k as parameter and shiow that is heap or not
//
bool heap_::isheap(int *arr, int n,int k) {

    if(k==1)
        for(int i=0;i<=(n-2)/2;i++)
        {
            if((2*i+1)<=n && arr[i]<arr[(2*i+1)])
                return false;
            if((2*i+2)<=n && arr[i]<arr[(2*i+2)])
                return false;
        }
    else
        for(int i=0;i<=(n-2)/2;i++)
        {
            if((2*i+1)<=n && arr[i]>arr[(2*i+1)])
                return false;
            if((2*i+2)<=n && arr[i]>arr[(2*i+2)])
                return false;
        }
    return  true;

}