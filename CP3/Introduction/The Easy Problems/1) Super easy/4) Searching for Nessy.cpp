#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int N, a, b, Target;
    cin>>N;
    for(int n=0; n<N; n++){
        cin>>a>>b;
        Target=ceil(double(a-2)/3)*ceil(double(b-2)/3);
        cout<<Target<<endl;
    }
    return 0;
}
