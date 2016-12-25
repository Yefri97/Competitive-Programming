#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        if(s.size()==5){
            cout<<"3"<<endl;
        }else{
            int cont=0;
            if(s[0]=='o') cont++;
            if(s[1]=='n') cont++;
            if(s[2]=='e') cont++;
            if(cont>1){
                cout<<"1"<<endl;
            }else{
                cout<<"2"<<endl;
            }
        }
    }
    return 0;
}
