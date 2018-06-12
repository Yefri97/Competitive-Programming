#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

bool cmp(string &a, string &b) {
	return a.size() < b.size();
}

bool check(string &a, string &b) {
	int n = a.size(), m = b.size();
	fori(i, 0, m - n + 1)
		if (b.substr(i, n) == a)
			return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vector<string> v(n);
	fori(i, 0, n)
		cin >> v[i];
	sort(v.begin(), v.end(), cmp);
	int ok = 1;
	fori(i, 1, n)
		ok &= check(v[i - 1], v[i]);
	if (!ok) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	fori(i, 0, n)
		cout << v[i] << endl;
	return 0;
}
