#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define sq(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int oo = 1e9, mxn = 40;

int n, res[mxn][mxn], p[mxn], f, s, t, total;

void augment(int v, int minEdge) {
	if (v == s) { f = minEdge; return; }
	else if (p[v] != -1) {
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f; res[v][p[v]] += f;
	}
}

int maxFlow() {
	int mf = 0;
	while (true) {
		f = 0;

		vi dist(mxn, oo); dist[s] = 0;
		queue<int> q; q.push(s);
		memset(p, -1, sizeof p);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (u == t) break;
			fori(v, 0, n) {
				if (res[u][v] > 0 && dist[v] == oo) {
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		
		augment(t, oo);
		if (f == 0) break;
		mf += f;
	}
	return mf;
}

vector<string> splitLine(string line) {
	istringstream iss(line);
	vector<string> tokens;
	copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter(tokens));
	return tokens;
}

void process(string line) {
	vector<string> vs = splitLine(line);
	int app = (vs[0][0] - 'A') + 1, m = (vs[0][1] - '0');
	res[s][app] += m;
	total += m;
	fori(i, 0, (int)vs[1].size() - 1)
		res[app][27 + (vs[1][i] - '0')]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	n = 38;
	s = 0;
	t = n - 1;
	string line;
	while (getline(cin, line)) {
		total = 0;
		memset(res, 0, sizeof res);
		process(line);
		while (getline(cin, line) && line.size())
			process(line);
		fori(i, 0, 10)
			res[27 + i][t]++;
		int mf = maxFlow();
		if (mf < total) {
			cout << "!" << endl;
		} else {
			string ans(10, '_');
			fori(i, 0, 10)
				fori(j, 0, 26)
					if (res[27 + i][1 + j] > 0)
						ans[i] = j + 'A';
			cout << ans << endl;
		}
	}
	return 0;
}