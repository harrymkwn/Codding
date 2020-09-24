#include<iostream>
#include<sstream>
#include<string>



int main(){
    std::string stringvalues = "10,20,30";
    std::istringstream iss(stringvalues);

    for (size_t i = 0; i < 3; i++)
    {
        int val;
        iss>>val;
        std::cout<<val*2<<"\n";
    }
    return 0;
    
}