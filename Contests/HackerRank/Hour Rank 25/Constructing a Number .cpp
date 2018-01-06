#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, acc = 0; cin >> n;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            while (x) {
                acc += x % 10;
                x /= 10;
            }
        }
        cout << (acc % 3 == 0 ? "Yes" : "No") << endl;
    }
    return 0;
}