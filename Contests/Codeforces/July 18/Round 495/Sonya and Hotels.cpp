#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int check(vi &a, int p, int d) {
	int n = a.size();
	fori(i, 0, n) {
		if (a[i] == p || abs(a[i] - p) < d)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, d; cin >> n >> d;
	vi a(n);
	fori(i, 0, n)
		cin >> a[i];
	sort(a.begin(), a.end());
	set<int> dict;
	fori(i, 0, n) {
		if (check(a, a[i] - d, d))
			dict.insert(a[i] - d);
		if (check(a, a[i] + d, d))
			dict.insert(a[i] + d);
	}
	cout << dict.size() << endl;
	return 0;
}
