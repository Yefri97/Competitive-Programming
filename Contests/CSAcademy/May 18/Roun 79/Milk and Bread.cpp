#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    int ans = min(abs(c - a) + abs(a - b), abs(c - b) + abs(b - a));
    cout << ans << endl;
    return 0;
}