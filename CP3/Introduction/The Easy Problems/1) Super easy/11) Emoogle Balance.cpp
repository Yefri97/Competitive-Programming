#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    for(int i=0; cin>>n && n; i++){
        int a=0, b=0;
        while(n--){
            int num;
            cin>>num;
            if(num){
                a++;
            }else{
                b++;
            }
        }
        cout<<"Case "<<i+1<<": "<<a-b<<endl;
    }
    return 0;
}
