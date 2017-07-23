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
typedef pair<int, ii> iii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 4010;

int n;
vector<iii> g[mxn];
map<string, int> mapper;

int dijkstra(ii s, ii t) {
	if (s.first == -1) return -1;
	vector<vi> dist(n, vi(27, oo)); dist[s.first][s.second] = 0;
	priority_queue<iii, vector<iii>, greater<iii> > pq; pq.push(iii(0, s));
	while (!pq.empty()) {
		iii front = pq.top(); pq.pop();
		int d = front.first, u = front.second.first, c = front.second.second;
		if (u == t.first) return dist[u][c];
		if (d > dist[u][c]) continue;
		fori(i, 0, g[u].size()) {
			iii v = g[u][i];
			if (c == v.second.second) continue;
			if (dist[u][c] + v.first < dist[v.second.first][v.second.second]) {
				dist[v.second.first][v.second.second] = dist[u][c] + v.first;
				pq.push(iii(dist[v.second.first][v.second.second], v.second));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int m;
	while (cin >> m && m) {
		string s, t; cin >> s >> t;
		fori(i, 0, mxn) g[i].clear();
		mapper.clear();
		n = 0;
		fori(i, 0, m) {
			string a, b, w; cin >> a >> b >> w;
			if (mapper[a] == 0) mapper[a] = ++n;
			if (mapper[b] == 0) mapper[b] = ++n;
			int x = mapper[a] - 1, y = mapper[b] - 1, c = w[0] - 'a';
			g[x].push_back(iii(w.size(), ii(y, c)));
			g[y].push_back(iii(w.size(), ii(x, c)));
		}
		int ans = dijkstra(ii(mapper[s] - 1, 26), ii(mapper[t] - 1, 26));
		if (ans == -1)
			cout << "impossivel" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}