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

int solve(int n, string s, string t, vi &ans) {
	for (int i = n - 1; i >= 0; i--) {
		int j = i;
		while (j >= 0 && s[j] != t[i])
			j--;
		if (j < 0) return 0;
		fori(k, j, i) {
			swap(s[k], s[k + 1]);
			ans.push_back(k);
		}
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	string t; cin >> t;
	vi ans;
	if (solve(n, s, t, ans)) {
		cout << SZ(ans) << endl;
		for (int x : ans)
			cout << x + 1 << " ";
		cout << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
