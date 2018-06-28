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
	int n, m; cin >> n >> m;
	int k = n / m;
	vi v(n), c(n);
	fori(i, 0, n)
		cin >> v[i];
	fori(i, 0, n)
		c[i] = v[i] % m;
	vector<vi> p(m);
	fori(i, 0, n)
		p[c[i]].push_back(i);
	vi f;
	ll ans = 0;
	fori(j, 0, 2) {
		fori(i, 0, m) {
			while (p[i].size() > k) {
				f.push_back(p[i].back());
				p[i].pop_back();
			}
			while (p[i].size() < k && f.size() > 0) {
				int u = f.back();
				f.pop_back();
				p[i].push_back(u);
				int x = (i - c[u] + m) % m;
				v[u] += x;
				ans += x;
			}
		}
	}
	cout << ans << endl;
	fori(i, 0, n)
		cout << v[i] << " ";
	cout << endl;
	return 0;
}
