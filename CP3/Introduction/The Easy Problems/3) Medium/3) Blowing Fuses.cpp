#include<bits/stdc++.h>
using namespace std;

int state[5] = {-1, 1};

int main() {
    int n, m, c;
    for(int s = 1; cin>>n>>m>>c && n!=0 && m!=0 && c!=0; s++) {
        bool flag = true;
        vector< pair<int, int> > v(30);
        for(int i = 1; i <= n; i++) {
            int num; cin>>num;
            v[i] = make_pair(num, 0);
        }
        int mayor = 0, target = 0;
        for(int i = 0; i < m; i++) {
            int devices; cin>>devices;
            v[devices].second = !v[devices].second;
            target += state[v[devices].second]*v[devices].first;
            if(target > c) {
                flag = false;
            } else {
                mayor = (target > mayor)? target : mayor;
            }
        }
        cout<<"Sequence "<<s<<endl;
        if(flag) {
            cout<<"Fuse was not blown."<<endl;
            cout<<"Maximal power consumption was "<<mayor<<" amperes."<<endl;
        } else {
            cout<<"Fuse was blown."<<endl;
        }
        cout<<endl;
    }
    return 0;
}
