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

const int oo = 1e9, mxn = 2010;

int mx[] = {0, 1, 0, -1};
int my[] = {-1, 0, 1, 0};

int solver(set<ii> &s, set<ii> &t) {
	vector<vi> dist(mxn, vi(mxn, oo));
	queue<ii> q;
	for (set<ii>::iterator it = s.begin(); it != s.end(); it++) {
		ii pos = *it;
		dist[pos.first][pos.second] = 0;
		q.push(pos);
	}
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		if (t.find(u) != t.end()) return dist[u.first][u.second];
		int x = u.first, y = u.second;
		fori(k, 0, 4) {
			int nx = x + mx[k], ny = y + my[k];
			if (nx < 0 || nx >= mxn || ny < 0 || ny >= mxn) continue;
			if (dist[nx][ny] == oo) {
				dist[nx][ny] = dist[x][y] + 1;
				q.push(ii(nx, ny));
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int pa;
	while (cin >> pa && pa) {
		set<ii> source, target;
		fori(i, 0, pa) {
			int x, y; cin >> x >> y;
			source.insert(ii(x, y));
		}
		int pb; cin >> pb;
		fori(i, 0, pb) {
			int x, y; cin >> x >> y;
			target.insert(ii(x, y));
		}
		int ans = solver(source, target);
		cout << ans << endl;
	}

	return 0;
}