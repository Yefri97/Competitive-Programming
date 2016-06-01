#include<bits/stdc++.h>
using namespace std;

bool search_v(int n, vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == n) {
            return true;
        }
    }
    return false;
}

int main() {
    int k, m;
    while (cin>>k && k) {
        cin>>m;
        vector<int> v;
        string target = "yes";
        while (k--) {
            int num; cin>>num;
            v.push_back(num);
        }
        while (m--) {
            int c, r; cin>>c>>r;
            int cont = 0;
            while (c--) {
                int num; cin>>num;
                if (search_v(num, v)) {
                    cont++;
                }
            }
            if (cont < r) {
                target = "no";
            }
        }
        cout<<target<<endl;
    }
    return 0;
}
