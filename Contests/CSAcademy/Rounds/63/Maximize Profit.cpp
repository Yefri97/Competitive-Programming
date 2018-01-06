#include <bits/stdc++.h>
using namespace std;

int main() {
    double s, k;
    int q;
    cin >> s >> q >> k;
    vector<double> v(q);
    for (int i = 0; i < q; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    double ans = s;
    for (int i = 0; i < q; i++)
        ans += max((ans * v[i]) / 100.0, k);
    cout << fixed << setprecision(6) << ans << endl;
}