
// C++ program to demonstrate static 
// variables inside a class 
  
#include<bits/stdc++.h> 
using namespace std; 
  
class GfG 
{ 
   public: 
     static int i;

     GfG(){
       i = 1;
     } 
}; 
  

int main() 
{ 
  GfG obj1; 
  GfG obj2; 
  obj1.i =2; 
  obj2.i = 3; 
    
  // prints value of i 
  cout << obj1.i<<" "<<obj2.i;    
} 