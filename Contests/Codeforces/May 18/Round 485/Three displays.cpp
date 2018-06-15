#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	vi s(n), c(n);
	fori(i, 0, n)
		cin >> s[i];
	fori(i, 0, n)
		cin >> c[i];
	int ans = oo;
	fori(j, 1, n - 1) {
		int a = -1;
		fori(i, 0, j)
			if (s[i] < s[j] && (a == -1 || c[i] < c[a]))
				a = i;
		int b = -1;
		fori(k, j + 1, n)
			if (s[j] < s[k] && (b == -1 || c[k] < c[b]))
				b = k;
		if (a == -1 || b == -1) continue;
		ans = min(ans, c[a] + c[j] + c[b]);
	}
	cout << (ans < oo ? ans : -1) << endl;
	return 0;
}
