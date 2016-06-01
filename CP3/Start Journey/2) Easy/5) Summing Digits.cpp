#include<bits/stdc++.h>

using namespace std;

int main(){
    int N, target;
    while(cin>>N && N){
        target=N;
        while(N/10){
            target=N%10;
            while(N/=10){
                target += N%10;
            }
            N=target;
        }
        cout<<target<<endl;
    }
    return 0;
}
