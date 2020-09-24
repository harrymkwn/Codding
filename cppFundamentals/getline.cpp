#include<iostream>
#include<sstream>
#include<string>
using namespace std;
int main(){
    // std::string token;
    // std::string abc;
    // std::cin>>abc;
    // std::istringstream iss(abc);
    // while (std::getline(iss,token,','))
    // {
    //     std::cout<<token<<"\n";
    // }
    int x,y;
    while (cin>>x>>y)
    {
        cout<<x%y<<"\n";
    }
    
}

//getline takes stream , string and delimeter 