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
	vector<ll> v(n + 1);
	fori(i, 1, n + 1)
		cin >> v[i];
	fori(i, 1, n + 1)
		v[i] += v[i - 1];
	int it = 0;
	fori(i, 0, m) {
		ll d; cin >> d;
		while (it < n && v[it] < d) it++;
		cout << it << " " << d - v[it - 1] << endl;
	}
	return 0;
}
