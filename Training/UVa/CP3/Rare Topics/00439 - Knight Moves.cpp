// Knight Moves
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

int mi[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int mj[] = {-2, -1, 1, 2, 2, 1, -1, -2};

int solver(ii s, ii t) {
	vector<vi> d(8, vi(8, INF)); d[s.first][s.second] = 0;
	queue<ii> q; q.push(s);
	while (!q.empty()) {
		ii u = q.front(); q.pop();
		if (u.first == t.first && u.second == t.second) return d[u.first][u.second];
		for (int k = 0; k < 8; k++) {
			ii v = ii(u.first + mi[k], u.second + mj[k]);
			if (v.first < 0 || v.first >= 8 || v.second < 0 || v.second >= 8) continue;
			if (d[v.first][v.second] == INF) {
				d[v.first][v.second] = d[u.first][u.second] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b;
	while (cin >> a >> b) {
		ii init = ii(a[0] - 'a', a[1] - '0' - 1), end = ii(b[0] - 'a', b[1] - '0' - 1);
		int result = solver(init, end);
		cout << "To get from " << a << " to " << b << " takes " << result << " knight moves." << endl;
	}
	return 0;
}