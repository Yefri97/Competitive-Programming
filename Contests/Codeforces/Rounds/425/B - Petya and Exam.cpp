#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

set<char> st;

bool isgood(char c) { return st.find(c) != st.end(); }

bool check(string s, string q) {
	if (s.size() != q.size()) return false;
	fori(i, 0, s.size()) {
		if (s[i] == '?') {
			if (!isgood(q[i])) return false;
		} else {
			if (s[i] != q[i]) return false;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string good; cin >> good;
	fori(i, 0, good.size()) st.insert(good[i]);
	string s; cin >> s;
	int pos = 0;
	while (pos < s.size() && s[pos] != '*') pos++;
	int n; cin >> n;
	while (n--) {
		string q; cin >> q;
		bool ans = true;
		if (pos == s.size()) {
			ans = check(s, q);
		} else {
			if (s.size() - 1 > q.size()) { cout << "NO" << endl; continue; }
			string a = s.substr(0, pos), b = q.substr(0, pos);
			ans &= check(a, b);
			int len = s.size() - pos - 1;
			a = s.substr(pos + 1, len), b = q.substr(q.size() - len, len);
			ans &= check(a, b);
			fori(i, pos, q.size() - len)
				ans &= (!isgood(q[i]));
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}