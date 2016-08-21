#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    int N, x, Target=0;
    string s;
    cin>>N;
    while(N--){
        cin>>s;
        if(s == "donate"){
            cin>>x;
            Target += x;
        }else{
            cout<<Target<<endl;
        }
    }
    return 0;
}
