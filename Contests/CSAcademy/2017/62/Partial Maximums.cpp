#include <bits/stdc++.h>
using namespace std;

const int MX = 200010;

int A[MX];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    set<int> dict;
    map<int, int> mapper;
    int fb = -1, sb = -1;
    for (int i = 0; i < n; i++) {
        int x = A[i];
        if (x > fb) {
            dict.insert(x);
            sb = fb;
            fb = x;
        } else if (x > sb) {
            mapper[fb]++;
            sb = x;
        }
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        int a = A[i], b = mapper[A[i]], d = dict.size();
        if (dict.find(a) != dict.end()) d--;
        ans = max(ans, b + d);
    }
    cout << ans << endl;
    return 0;
}