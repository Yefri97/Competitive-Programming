#include <bits/stdc++.h>
using namespace std;

const int MX = 100000;

int A[MX], B[MX];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    string ans(n, '1');
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && A[i] < A[i + 1]) ans[i] = '0';
        if (i - 1 > 0 && B[i] < B[i - 1]) ans[i] = '0';
    }
    cout << ans << endl;
    return 0;
}