#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    int N, l, w, h;
    cin>>N;
    for(int n=0; n<N; n++){
        cin>>l>>w>>h;
        cout<<"Case "<<n+1<<": ";
        if(l<=20 && w<=20 && h<=20){
            cout<<"good"<<endl;
        }else{
            cout<<"bad"<<endl;
        }
    }
    return 0;
}
