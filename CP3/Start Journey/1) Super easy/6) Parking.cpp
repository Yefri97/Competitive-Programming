#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int T, N, menor, mayor;
    vector<int> v(30);
    cin>>T;
    for(int t=0; t<T; t++){
        cin>>N;
        for(int n=0; n<N; n++){
            cin>>v[n];
        }
        sort(v.begin(), v.begin()+N);
        menor=v[0];
        mayor=v[N-1];
        cout<<2*(mayor-menor)<<endl;
    }
    return 0;
}
