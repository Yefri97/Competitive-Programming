#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    long long ans = 0;
    for (int i = 0; i < n / 3; i++) {
        ans += a[2 * i + 1];
    }
    cout << ans << endl;
    return 0;
}