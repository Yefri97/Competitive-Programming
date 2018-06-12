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
	int n, w; cin >> n >> w;
	vi v(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 1, n)
		v[i] += v[i - 1];
	int a = w;
	fori(i, 0, n)
		a = min(a, w - v[i]);
	int b = 0;
	fori(i, 0, n)
		b = max(b, -v[i]);
	int ans = max(0, a - b + 1);
	cout << ans << endl;
	return 0;
}
