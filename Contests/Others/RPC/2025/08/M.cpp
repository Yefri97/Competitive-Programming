#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 2 * a;
    if (c >= 2) {
        ans += 2 * b + 3;
        c -= 2;
    }
    ans += 3 * (c / 2);
    cout << ans << endl;
    return 0;
}