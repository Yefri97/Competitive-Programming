#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vi v;
	fori(i, 0, n) {
		int x; cin >> x;
		if (x > 0) continue;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	int acc = 0;
	fori(i, 0, min((int)v.size(), m))
		acc += v[i];
	cout << -acc << endl;
	return 0;
}