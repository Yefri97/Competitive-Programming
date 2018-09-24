#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 100010, MD = 483433999;

ll pol[MN], pt[MN];

ll fastExp(ll b, ll e) {
	ll ans = 1;
	while (e) {
		if (e & 1)
			ans = (ans * b) % MD;
		b = (b * b) % MD;
		e >>= 1;
	}
	return ans;
}

ll calc(int l, int r) {
	return ((pol[r] - (l > 0 ? pol[l - 1] : 0) + MD) * fastExp(pt[l], MD - 2)) % MD;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	pt[0] = 1;
	fori(i, 1, MN)
		pt[i] = (52 * pt[i - 1]) % MD;
	string s;
	while (cin >> s) {
		int n = s.size();
		fori(i, 0, n)
			pol[i] = (s[i] * pt[i]) % MD;
		fori(i, 1, n)
			pol[i] = (pol[i] + pol[i - 1]) % MD;
		set<int> dict;
		stack<int> st;
		fori(i, 0, n) {
			if (s[i] == '(') {
				st.push(i);
			} else if (s[i] == ')') {
				int pos = st.top(); st.pop();
				dict.insert(calc(pos + 1, i - 1));
			} else if (s[i] == ',') {
				int pos = st.top(); st.pop();
				dict.insert(calc(pos + 1, i - 1));
				st.push(i);
			}
		}
		cout << dict.size() + 1 << endl;
	}
	return 0;
}
