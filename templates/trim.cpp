#include<bits/stdc++.h>
using namespace std;


//mutable types of trim functions
void rtrim(string& s, const string& delimiters = " \f\n\r\t\v" )
{
   s.erase( s.find_last_not_of( delimiters ) + 1 );

}

void ltrim(string& s,  const string& delimiters = " \f\n\r\t\v" )
{
   s.erase( 0, s.find_first_not_of( delimiters ) );
}
 
void trim(string& s, const string& delimiters = " \f\n\r\t\v" )
{
    s.erase( s.find_last_not_of( delimiters ) + 1 ).erase( 0, s.erase( s.find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
}




//return type trim functions
string rtrim(string s, const string& delimiters = " \f\n\r\t\v" )
{
    s.erase( s.find_last_not_of( delimiters ) + 1 );
    return s;
}
string ltrim(string s,  const string& delimiters = " \f\n\r\t\v" )
{
    s.erase( 0, s.find_first_not_of( delimiters ) );
    return s;
}
string trim(string s, const string& delimiters = " \f\n\r\t\v" )
{
    s.erase( s.find_last_not_of( delimiters ) + 1 ).erase( 0, s.erase( s.find_last_not_of( delimiters ) + 1 ).find_first_not_of( delimiters ) );
    return s;
}

int main(){
    
    return 0;
}