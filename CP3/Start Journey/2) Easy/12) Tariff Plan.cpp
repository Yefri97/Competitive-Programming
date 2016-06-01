#include<bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    for(int t=0; t<T; t++){
        int n; cin>>n;
        int a=0, b=0;
        while(n--){
            int num; cin>>num;
            a += (floor(double(num)/30)+1)*10;
            b += (floor(double(num)/60)+1)*15;
        }
        cout<<"Case "<<t+1<<": ";
        if(a == b){
            cout<<"Mile Juice "<<a<<endl;
        }else if(a < b){
            cout<<"Mile "<<a<<endl;
        }else{
            cout<<"Juice "<<b<<endl;
        }
    }
    return 0;
}
