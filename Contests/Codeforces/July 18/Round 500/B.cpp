#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define SZ(v) (int)v.size()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int check(vi &a, vi &b) {
	int n = a.size();
	set<int> dict;
	fori(i, 0, n) {
		if (dict.count(a[i])) return 1;
		dict.insert(b[i]);
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, x; cin >> n >> x;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	if (check(a, a)) { cout << 0 << endl; return 0; }
	vi b(n);
	fori(i, 0, n)
		b[i] = a[i] & x;
	if (check(a, b)) { cout << 1 << endl; return 0; }
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (check(a, b)) { cout << 1 << endl; return 0; }
	if (check(b, b)) { cout << 2 << endl; return 0; }
	cout << -1 << endl;
	return 0;
}
