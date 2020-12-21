#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    while(n--){
        int temp,sum = 0;
        cin>>temp;
        while(temp>0){
            sum += temp%10;
            temp /= 10;
        }
        cout<<sum<<"\n";
    }    
	return 0;
}
