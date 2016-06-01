#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main(){
    int N;
    vector<int> v(5);
    cin>>N;
    for(int n=0; n<N; n++){
        cin>>v[0]>>v[1]>>v[2];
        sort(v.begin(), v.begin()+3);
        cout<<"Case "<<n+1<<": "<<v[1]<<endl;
    }
    return 0;
}
