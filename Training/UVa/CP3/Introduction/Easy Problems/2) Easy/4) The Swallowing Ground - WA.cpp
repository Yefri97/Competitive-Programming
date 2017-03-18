#include<bits/stdc++.h>

using namespace std;

int main(){
    int Z, N, a, b, target;
    bool flag;
    cin>>Z;
    while(Z--){
        flag=true;
        cin>>N;
        cin>>a>>b;
        N--;
        target=abs(a-b);
        while(N--){
            cin>>a>>b;
            if(abs(a-b)!=target){
                flag=false;
            }
        }
        if(flag){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
        cout<<endl;
    }
    return 0;
}
