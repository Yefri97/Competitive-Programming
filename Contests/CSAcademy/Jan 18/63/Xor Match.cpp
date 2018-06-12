#include <bits/stdc++.h>
using namespace std;

const int MX = 1000;
int A[MX], B[MX];

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    int ans = 0;
    for (int i = 0; i + n <= m; i++) {
        int b = 1;
        for (int j = 0; j < n; j++)
            b &= A[j] + B[i + j] == 1;
        ans += b;
    }
    cout << ans << endl;
    return 0;
}