#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MK = 20;

int main() {
    int n, m;
    cin >> n >> m;
    int nn = 2 * n;
    vector<int> a(nn);
    vector<vector<int>> par(nn, vector<int>(MK, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[n + i] = a[i];
    }
    int l = 0, r = 0, sum = 0;
    // Two pointers
    while (l < nn) {
        while (r < nn && sum < m) {
            sum += a[r];
            r++;
        }
        if (r < nn) par[l][0] = r;
        sum -= a[l];
        l++;
    }
    // Binary lifting
    for (int k = 1; k < MK; k++) {
        for (int i = 0; i < nn; i++) {
            if (par[i][k - 1] == -1) continue;
            par[i][k] = par[par[i][k - 1]][k - 1];
        }
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        int u = i, sum = 0;
        for (int k = MK - 1; k >= 0; k--) {
            if (par[u][k] != -1 && par[u][k] < i + n) {
                u = par[u][k];
                sum += (1 << k);
            }
        }
        ans[i] = sum;
    }
    // Show answer
    for (int i = 0; i < n; i++) {
        if (i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
    return 0;
}