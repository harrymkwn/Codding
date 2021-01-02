#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char ch;
        cin>>ch;
        switch (ch)
        {
        case 'b':
            cout<<"BattleShip\n";
            break;
        case 'B':
            cout<<"BattleShip\n";
            break;
        case 'c':
            cout<<"Cruiser\n";
            break;
        case 'C':
            cout<<"Cruiser\n";
            break;
        case 'd':
            cout<<"Destroyer\n";
            break;
        case 'D':
            cout<<"Destroyer\n";
            break;
        case 'f':
            cout<<"Frigate\n";
            break;
        case 'F':
            cout<<"Frigate\n";
            break;

        default:
            cout<<"\n";
            break;
        }
    }
    return 0;
}