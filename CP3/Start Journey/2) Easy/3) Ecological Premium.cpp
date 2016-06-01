#include<bits/stdc++.h>
#define endl '\n'

using namespace std;

int main(){
    int N, f, a, b, c, cont;
    cin>>N;
    while(N--){
        cont=0;
        cin>>f;
        while(f--){
            cin>>a>>b>>c;
            cont+=a*c;
        }
        cout<<cont<<endl;
    }
    return 0;
}
