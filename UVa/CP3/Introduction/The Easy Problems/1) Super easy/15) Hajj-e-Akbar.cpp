#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    string s;
    for(int n=0; cin>>s && s!="*"; n++){
        cout<<"Case "<<n+1<<": Hajj-e-";
        if(s == "Hajj"){
            cout<<"Akbar";
        }else{
            cout<<"Asghar";
        }
        cout<<endl;
    }
    return 0;
}
