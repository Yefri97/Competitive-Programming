#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    int N;
    cin>>N;
    string s;
    while(N--){
        cin>>s;
        if(s=="1" || s=="4" || s=="78"){
            cout<<"+";
        }else if(s[s.size()-1] == '5'){
            cout<<"-";
        }else if(s[0] == '9'){
            cout<<"*";
        }else{
            cout<<"?";
        }
        cout<<endl;
    }
    return 0;
}
