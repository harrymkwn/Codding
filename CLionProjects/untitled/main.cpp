#include <bits/stdc++.h>
using namespace std;

class parent{
    int a=5;
    int b=5;

public:
    int sum(){
        return a+b;
    }
};


class sub : public parent{
    int c=5;

public:
    int sum(int c){
        return c;
    }
};

int main(){
    parent* a = new sub();
    cout<<a->sum();
}