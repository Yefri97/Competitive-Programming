/*
 *  RPC 02st Contest 2017
 *  Problem B: Buggy Robot
 *  Outcome: Accepted | Category: Single Source Shortest Path
 */
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 60, INF = 1000000;

int n, m, ans;
char board[MAXN][MAXN];
string command;

struct node {
	int i, j, id;
	node() {}
	node(int _i, int _j, int _id) : i(_i), j(_j), id(_id) {}
};

typedef pair<int, node> ii;

char cmd[] = {'L', 'U', 'R', 'D'};
int mi[] = {0, -1, 0, 1};
int mj[] = {-1, 0, 1, 0};

int sssp(node s, node t) {
	int target = INF;
	
	int dist[MAXN][MAXN][MAXN];
	memset(dist, INF, sizeof dist);
	dist[s.i][s.j][s.id] = 0;
	
	deque<ii> dq; dq.push_front(ii(0, s));
	
	while (!dq.empty()) {
		ii front = dq.front(); dq.pop_front();
		int d = front.first;
		node u = front.second;
		if (u.i == t.i and u.j == t.j)
			target = min(target, dist[u.i][u.j][u.id]);
		if (d > dist[u.i][u.j][u.id]) continue;
		for (int k = 0; k < 4; k++) {
			node v = node(u.i + mi[k], u.j + mj[k], u.id);
			if (v.i < 0 or v.i >= n or v.j < 0 or v.j >= m or board[v.i][v.j] == '#')
				v.i = u.i, v.j = u.j;
			if (u.id < command.size() and cmd[k] == command[u.id]) {
				v.id += 1;
				if (dist[u.i][u.j][u.id] < dist[v.i][v.j][v.id]) {
					dist[v.i][v.j][v.id] = dist[u.i][u.j][u.id];
					dq.push_front(ii(dist[v.i][v.j][v.id], v));
				}
			} else {
				if (dist[u.i][u.j][u.id] + 1 < dist[v.i][v.j][v.id]) {
					dist[v.i][v.j][v.id] = dist[u.i][u.j][u.id] + 1;
					dq.push_back(ii(dist[v.i][v.j][v.id], v));
				}
			}
		}
	}
	return target;
}

int main() {
	node r, e;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == 'R') r = node(i, j, 0);
			if (c == 'E') e = node(i, j, 0);
			board[i][j] = c;
		}
	}
	cin >> command;
	command.push_back('$');
	int ans = sssp(r, e);
	cout << ans << endl;
	return 0;
}