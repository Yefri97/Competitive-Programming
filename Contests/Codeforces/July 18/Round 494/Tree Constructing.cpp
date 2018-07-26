#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 400010;

int deg[MN], dist[MN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, d, k; cin >> n >> d >> k;
	if (k == 1 && d > 1 || n <= d) { cout << "NO" << endl; return 0; }
	vector<ii> ans;
	fori(i, 0, d)
		ans.push_back(ii(i, i + 1));
	stack<int> st;
	fori(i, 0, (d + 1) / 2) {
		st.push(i);
		st.push(d - i);
		deg[i] = deg[d - i] = 2;
		dist[i] = dist[d - i] = d - i;
	}
	if ((d + 1) % 2) {
		st.push(d / 2);
		deg[d / 2] = 2;
		dist[d / 2] = d / 2;
	}
	int idx = d + 1;
	while (idx < n && !st.empty()) {
		int u = st.top();
		if (deg[u] < k && dist[u] < d) {
			int v = idx++;
			ans.push_back(ii(u, v));
			st.push(v);
			dist[v] = dist[u] + 1;
			deg[v] = 1;
			deg[u]++;
		} else {
			st.pop();
		}
	}
	if (idx < n) { cout << "NO" << endl; return 0; }
	cout << "YES" << endl;
	fori(i, 0, n - 1)
		cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
	return 0;
}
