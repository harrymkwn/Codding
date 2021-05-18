
#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y;
	std::cin>>x>>y;
	

	bitset<16> foo;
	bitset<16> bar(0x1f2);
	bitset<16> baz(string("1101010101010"));
	
	for(int i=0;i<5;i++){
		cin>>x>>y;
		cout<<x<<y;
	}

	return 0;
}
