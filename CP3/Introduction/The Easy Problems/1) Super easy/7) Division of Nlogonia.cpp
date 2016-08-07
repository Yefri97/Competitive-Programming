#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int K, M, N, X, Y;
    bool flag;
    char Target[5];
    while(cin>>K && K){
        cin>>M>>N;
        while(K--){
            flag=true;
            cin>>X>>Y;
            if(Y<N){
                Target[0]='S';
            }else if(Y>N){
                Target[0]='N';
            }else{
                flag=false;
            }

            if(X<M){
                Target[1]='O';
            }else if(X>M){
                Target[1]='E';
            }else{
                flag=false;
            }

            if(flag){
                cout<<Target[0]<<Target[1]<<endl;
            }else{
                cout<<"divisa"<<endl;
            }
        }
    }
    return 0;
}
