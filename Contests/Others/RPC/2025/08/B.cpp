#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(m, -1), ans(m, 0);
    for (int i = 0; i < k; i++) {
        int p, c;
        cin >> p >> c;
        c--;
        if (a[c] == -1) {
            a[c] = p;
        } else {
            if (a[c] == p) ans[c] += 100;
            else ans[c] += abs(a[c] - p);
            a[c] = -1;
        }
    }
    for (int i = 0; i < m; i++) {
        if (a[i] != -1) ans[i] += 100;
    }
    for (int i = 0; i < m; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}