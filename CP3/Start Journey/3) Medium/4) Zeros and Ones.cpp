#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    for(int cases = 0; cin>>s; cases++) {
        int N; cin>>N;
        cout<<"Case "<<cases+1<<":"<<endl;
        for(int n = 0; n < N; n++) {
            int i, j; cin>>i>>j;
            int left = min(i, j), right = max(i, j);
            int zero = 0, one = 0;
            for(int a = left; a <= right; a++) {
                if(s[a] == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            if(zero && one){
                cout<<"No"<<endl;
            } else {
                cout<<"Yes"<<endl;
            }
        }
    }
    return 0;
}
