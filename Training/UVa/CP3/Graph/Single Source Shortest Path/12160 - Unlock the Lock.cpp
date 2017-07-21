#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9;

vi buttons;

int bfs(int s, int t) {
	vi dist(10000, oo); dist[s] = 0;
	queue<int> q; q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == t) return dist[u];
		fori(k, 0, buttons.size()) {
			int v = (u + buttons[k]) % 10000;
			if (dist[v] == oo) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int s, t, r, cs = 0;
	while (cin >> s >> t >> r && (s + t + r)) {
		buttons.clear();
		fori(i, 0, r) {
			int x; cin >> x;
			buttons.push_back(x);
		}
		int ans = bfs(s, t);
		cout << "Case " << ++cs << ": ";
		if (ans == -1)
			cout << "Permanently Locked" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}