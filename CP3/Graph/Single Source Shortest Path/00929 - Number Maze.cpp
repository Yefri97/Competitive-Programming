#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int maxn = 1000, INF = 1e7;

int mi[5] = {1, 0, -1, 0};
int mj[5] = {0, 1, 0, -1};

int n, m, board[maxn + 10][maxn + 10];

int dijkstra(ii ini) {
	vector< vector<int> > dist(n, vector<int>(m, INF)); dist[ini.first][ini.second] = board[ini.first][ini.second];
	priority_queue<iii, vector<iii>, greater<iii> > pq; pq.push(iii(board[ini.first][ini.second], ini));
	while (!pq.empty()) {
		iii front = pq.top(); pq.pop();
		int d = front.first;
		ii u = front.second;
		if (d > dist[u.first][u.second]) continue;
		for (int i = 0; i < 4; i++) {
			ii v = ii(u.first + mi[i], u.second + mj[i]);
			if (v.first < 0 || v.first >= n || v.second < 0 || v.second >= m) continue;
			if (dist[u.first][u.second] + board[v.first][v.second] < dist[v.first][v.second]) {
				dist[v.first][v.second] = dist[u.first][u.second] + board[v.first][v.second];
				pq.push(iii(dist[v.first][v.second], v));
			}
		}
	}
	return dist[n - 1][m - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				cin >> board[i][j];
		int ans = dijkstra(ii(0, 0));
		cout << ans << endl;
	}
	return 0;
}