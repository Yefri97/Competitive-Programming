#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int N, a, b, Target;
    cin>>N;
    for(int n=0; n<N; n++){
        cin>>a>>b;
        a-=2;
        b-=2;
        a = ceil(double(a)/3);
        b = ceil(double(b)/3);
        Target=a*b;
        cout<<Target<<endl;
    }
    return 0;
}
