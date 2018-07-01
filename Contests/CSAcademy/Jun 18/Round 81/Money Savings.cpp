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
	int n, x; cin >> n >> x;
	vi a(n), b(n);
	fori(i, 0, n)
		cin >> a[i] >> b[i];
	int curr = x;
	fori(k, 0, 12) {
		int c = 0;
		fori(i, 0, n) if (curr >= a[i])
			c = max(c, b[i] - a[i]);
		curr += c;
	}
	cout << curr << endl;
	return 0;
}
