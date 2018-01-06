#include <bits/stdc++.h>
using namespace std;

const int oo = 1e9, MX = 1e5;

int n;
int A[MX], B[MX], C[MX];

int solver() {
    for (int i = 0; i < n; i++) {
        if (B[i] > A[i]) return -1;
        C[i] = A[i] - B[i];
    }
    int g = 0, mx = *max_element(B, B + n);
    for (int i = 0; i < n; i++)
        g = __gcd(g, C[i]);
    int ans = oo;
    for (int i = 1; i * i <= g; i++) if (g % i == 0) {
        int a = i, b = g / i;
        if (a > mx) ans = min(ans, a);
        if (b > mx) ans = min(ans, b);
    }
    return ans == oo ? -1 : ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    int ans = solver();
    cout << ans << endl;
}