#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, first = 1;
    while(cin>>N) {
        vector<string> vf(30);
        map<string, int> f;
        for(int n = 0; n < N; n++) {
            string s; cin>>s;
            f[s] = n;
            vf[n] = s;
        }
        vector< vector<int> > m(30, vector<int>(30));
        for(int n = 0; n < N; n++) {
            string give; cin>>give;
            int price; cin>>price;
            int nf; cin>>nf;
            m[f[give]][f[give]] = (nf)? -1*price + price%nf : nf;
            for(int i = 0; i < nf; i++) {
                string rec; cin>>rec;
                m[f[give]][f[rec]] = price/nf;
            }
        }
        if(!first) cout<<endl;
        first = 0;
        for(int b = 0; b < N; b++) {
            int target = 0;
            for(int a = 0; a < N; a++) {
                target += m[a][b];
            }
            cout<<vf[b]<<" "<<target<<endl;
        }
    }
    return 0;
}
