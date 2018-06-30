#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int freq[10];
ll fact[20];

ll calc() {
	ll p = 0, q = 1;
	fori(i, 0, 10) {
		p += freq[i];
		q *= fact[freq[i]];
	}
	ll ans = fact[p] / q;
	fori(i, 0, freq[0]) {
		p--;
		q /= (freq[0] - i);
		fori(j, 1, 10) if (freq[j] > 0)
			ans -= (fact[p - 1] * freq[j]) / q;
	}
	return ans;
}

ll solve(int id) {
	if (id == 10) return calc();
	ll ans = solve(id + 1);
	if (freq[id] > 1) {
		freq[id]--;
		ans += solve(id);
		freq[id]++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	fact[0] = 1;
	fori(i, 1, 20)
		fact[i] = i * fact[i - 1];
	string s; cin >> s;
	int n = s.size();
	fori(i, 0, n)
		freq[s[i] - '0']++;
	ll ans = solve(0);
	cout << ans << endl;
	return 0;
}
