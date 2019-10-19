
#include<bits/stdc++.h>
using namespace std;

int main() {
    string str;

    int n;
    cin>>n;
    cin>>str;
    int count=n;
    for(int i=0;i<count-1;i++)
    {
        if(str[i]==str[i+1] && i%2==0) {
            str.erase(str.begin() + i);
            i--;
            count--;
        }
    }
    if(str.length()%2==0)
        cout<<n-str.length();
    else {
        cout << n - str.length()+1;
        str.pop_back();
    }

    cout<<"\n"<<str;


}

