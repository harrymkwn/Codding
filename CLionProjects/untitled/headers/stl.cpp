//
// Created by harry on 10/6/19.
//
#include <bits/stdc++.h>
using namespace std;
#include "stl.h"

void stl::showlist(list<int> ls){
    list<int> ::iterator it;

    for(auto it=ls.begin();it!=ls.end();it++)
        cout<<*it<<" ";

    cout<<"\n";
}

void stl::liststl() {

    list<int > list1;
    list<int> ::iterator it=list1.begin(),it2=list1.begin();
    for (int i = 0; i <5 ; ++i) {
        list1.push_back(i);
    }
    stl::showlist(list1);

    list1.push_back(5);
    list1.push_front(-1);
    showlist(list1);

    list1.insert(list1.begin(),2,7);
    showlist(list1);

    advance(it,5);
    list1.insert(it,2,7);
    showlist(list1);

    cout<<list1.empty();

    list1.erase(it);
//    advance(it1,3);
//    list1.erase(it2,it1);
    showlist(list1);

    list<int> demo_list;
    demo_list.assign(5, 100);  //it is used to assign values to noely defined list and also used to assign whole list to another
    showlist(demo_list);

    list1.remove(7);
    showlist(list1);

}