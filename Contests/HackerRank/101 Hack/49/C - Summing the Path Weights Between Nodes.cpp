#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl;
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 100010, MAXM = 100010;

vector<int> tree[MAXN];
int color[MAXN], from[MAXM], to[MAXM];
bool visited[MAXN];
ll weight[MAXN], memo[MAXN][2];

void count(int u) {
	visited[u] = true;
	memo[u][color[u]]++;
	fori(i, 0, tree[u].size()) {
		int e = tree[u][i];
		int v = (from[e] + to[e]) - u;
		if (visited[v]) continue;
		from[e] = u; to[e] = v;
		count(v);
		memo[u][0] += memo[v][0];
		memo[u][1] += memo[v][1];
	}
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  fori(i, 0, n)
  	cin >> color[i];
  fori(i, 0, n - 1) {
  	int u, v, w; cin >> u >> v >> w; u--; v--;
  	from[i] = u;
  	to[i] = v;
  	weight[i] = w;
  	tree[u].push_back(i);
  	tree[v].push_back(i);
  }
  memset(memo, 0, sizeof memo);
  count(0);
  ll ans = 0;
  fori(i, 0, n - 1)
  	ans += weight[i] * (memo[to[i]][0] * (memo[0][1] - memo[to[i]][1]) + memo[to[i]][1] * (memo[0][0] - memo[to[i]][0]));
  cout << ans << endl;
  return 0;
}