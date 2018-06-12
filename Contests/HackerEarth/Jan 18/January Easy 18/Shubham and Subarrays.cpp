#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int base1 = 127, base2 = base1 + 2;
const int mod1 = 1e9 + 7, mod2 = mod1 + 2;
const int MX = 1e3 + 10;

int A[MX];
ll pow1[MX], pow2[MX];

int main() {
    pow1[0] = pow2[0] = 1;
    for (int i = 1; i < MX; i++) {
        pow1[i] = (base1 * pow1[i - 1]) % mod1;
        pow2[i] = (base2 * pow2[i - 1]) % mod2;
    }
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    set<ii> dict;
    for (int i = 0; i < n; i++) {
        bitset<MX> bs;
        int hval1 = 0, hval2 = 0;
        for (int j = i; j < n; j++) {
            if (!bs.test(A[j])) {
                hval1 = (hval1 + pow1[A[j]]) % mod1;
                hval2 = (hval2 + pow2[A[j]]) % mod2;
            }
            bs.set(A[j]);
            dict.insert(ii(hval1, hval2));
        }
    }
    int ans = dict.size();
    cout << ans << endl;
    return 0;
}