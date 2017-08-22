#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int min_val = INF, max_val = 0;
	vector<iii> v(n);
	fori(i, 0, n) {
		int a, b; cin >> a >> b;
		v[i] = iii(ii(a, b), i);
		min_val = min(min_val, a);
		max_val = max(max_val, b);
	}
	sort(v.begin(), v.end());
	int it = 0;
	while (v[it].first.first == min_val) it++;
	if (v[it - 1].first.second == max_val)
		cout << v[it - 1].second + 1 << endl;
	else
		cout << -1 << endl;
	return 0;
}