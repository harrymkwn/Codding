#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int x,temp,sum = 0;
        cin>>temp;
        x=temp;
        sum = temp %10;
        while(temp>=10){
            temp /= 10;
        }
        cout<<sum + temp<<"\n";
        // else cout<<sum<<"\n";
    }    
	return 0;
}
