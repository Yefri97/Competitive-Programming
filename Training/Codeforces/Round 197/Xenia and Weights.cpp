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

const int oo = 1e9;

string line;
int m, vis[1000][20][20];
vi seq;

bool dfs(int id, int w, int prev) {
	vis[id][10 + w][prev] = 1;
	if (id == m) return true;
	fori(i, 0, 10) {
		if (line[i] == '1' && i != prev && (w < 0 && (w + (i + 1) > 0) || w >= 0 && (w - (i + 1) < 0))) {
			int nw = w < 0 ? w + (i + 1) : w - (i + 1);
			if (vis[id + 1][10 + nw][i]) continue;
			seq.push_back(i + 1);
			if (dfs(id + 1, nw, i)) return true;
			seq.pop_back();
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	while (cin >> line >> m) {
		bool ans = dfs(0, 0, 11);
		if (ans) {
			cout << "YES" << endl;
			fori(i, 0, (int)seq.size())
				cout << seq[i] << " ";
			cout << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}