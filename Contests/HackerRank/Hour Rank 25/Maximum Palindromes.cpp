#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MX = 1e5, MD = 1e9 + 7;

int presum[30][MX];
ll fact[MX], inv_fact[MX];

ll fast_exp(ll b, ll e) {
    if (e == 0) return 1;
    ll ans = fast_exp(b, e / 2); ans = (ans * ans) % MD;
    if (e % 2) ans = (ans * b) % MD;
    return ans;
}

ll answerQuery(int l, int r) {
    vector<int> freq(26);
    for (int i = 0; i < 26; i++)
        freq[i] = presum[i][r] - (l == 0 ? 0 : presum[i][l - 1]);
    int cnt = 0, acc = 0;
    for (int i = 0; i < 26; i++) {
        cnt += freq[i] % 2;
        freq[i] >>= 1;
        acc += freq[i];
    }
    ll result = fact[acc];
    for (int i = 0; i < 26; i++)
        result = (result * inv_fact[freq[i]]) % MD;
    if (cnt)
        result = (result * cnt) % MD;
    return result;
}

int main() {
    fact[0] = inv_fact[0] = 1;
    for (ll i = 1; i < MX; i++) {
        fact[i] = (i * fact[i - 1]) % MD;
        inv_fact[i] = fast_exp(fact[i], MD - 2);
    }
    string s; cin >> s;
    for (int i = 0; i < 26; i++) {
        presum[i][0] = (s[0] - 'a' == i);
        for (int j = 1; j < (int)s.size(); j++)
            presum[i][j] = (s[j] - 'a' == i) + presum[i][j - 1];
    }
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--; r--;
        ll result = answerQuery(l, r);
        cout << result << endl;
    }
    return 0;
}