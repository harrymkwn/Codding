#include <bits/stdc++.h>
using namespace std;

class node{

    public:
    node** children = new node*[26];
    bool end;
    node(){
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
        end = false;
    }
};

void insert(node * root , string str){

    for(int i=0;i<str.length();i++){
        if(i==str.length()-1)
            root->end = true;
        if(!root->children[str[i]-'a'])
            root->children[str[i]-'a'] = new node();
        root = root->children[str[i]-'a'];
    }
}

bool check(node* root){
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
            return false;
    }
    return true;
}


void complete_sentence(node * root,string str){
    
    
    if(check(root)){
        cout<<str<<"\n";
        return;
    }
    
    for(int i=0;i<26;i++){
        if(root->children[i]){
            str = str + (char)((int)i+'a');
            complete_sentence(root->children[i],str);
            str.pop_back();
        }
    }
}


void query(node * root , string str){
    node* head = root;
    for(int i=0;i<str.length();i++){
        if(!root->children[str[i]-'a'])
        {
            cout<<"No suggestions\n";
            insert(head,str);
            return;
        }    
        if(root->end && i==str.length()-1){
            for(int j=0;j<=i;j++)
                cout<<str[j];
            cout<<"\n";
        }
        
        
        root = root->children[str[i]-'a'];   
    }

    if(root)
    complete_sentence(root,str);
}

int main(){

    int n,m;
    std::ios_base::sync_with_stdio(false);
    cin>>n;
    node *head = new node();
    while(n--){
        string x;
        cin>>x;
        insert(head,x);
    }
    cin>>m;
    while(m--){
    string s;
    cin>>s;
        query(head,s);
    }
    delete head;
}
