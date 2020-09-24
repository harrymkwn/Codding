#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

/**
 * index of bitset will start from rmv(right most value) 
 *  ex: 0000111010     -:    index[0] = 0 ,index[1]=1
 * 
 * three types of constructor in bitset
 * 1) default constructor
 * 2) takes value using integer and others dtype (it will keep number as it is from right and out indexes are discarded)
 * 3) takes string and c-string (it will takes three parameters and string as it is in bitset)
 * 
 * 
 * functionality :
 * operator[]
 * size(),count(),test()(checks whether index is set or not returns boolean) ,
 * any(),all(),none()
 * 
 * set() takes three types of argument 1:)nothing : it will set all bits to 1 , 2:) two arguments first pos which to set and second what to set, 3:) one argumeent which is to set
 * 
 * reset() takes two types of arguments 1:) nothing set all bits as 0 ,2:) one argument set index to set to 0
 * 
 * flip() takes two types of arguments 1:) nothing to become 1`s complement ,2:) index to flip 
 * 
 *  
*/

int main()
{
    bitset<10> foo;
    bitset<10> bar(0xff3);
    bitset<10> baz(string("11101011111111111111111110"), 0, 6);

    cout << foo << " " << bar << " " << baz << "\n";

    cout<<  baz[0] <<" "<<baz[1]<<"\n";


    cout<<" ones in bitset : "<<baz.count()<<"\n";
    cout<<" zeroes in bitset : "<<baz.size() -  baz.count()<<"\n";


    cout<<baz.test(1)<<"\n";

    cout<<baz.all()<<"\n";

    cout<<baz.any()<<"\n";

    cout<<foo.none()<<"\n";

    string str = baz.to_string();
    cout<<str<<"\n";

    long long abc = baz.to_ullong();
    cout<<abc<<"\n";

    long a = baz.to_ulong();
    cout<<a<<"\n";


    hash<bitset<10>> h;
    size_t z = h(baz);
    return 0;
}