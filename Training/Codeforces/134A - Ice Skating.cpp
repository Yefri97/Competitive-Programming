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

const int oo = 1e9, mxn = 100;

int n;
int X[mxn], Y[mxn], visited[mxn];

void dfs(int u) {
	visited[u] = 1;
	fori(i, 0, n) if (u != i && (X[u] == X[i] || Y[u] == Y[i])){
		if (!visited[i])
			dfs(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	fori(i, 0, n)
		cin >> X[i] >> Y[i];
	int ans = 0;
	fori(i, 0, n)
		if (!visited[i])
			dfs(i), ans++;
	cout << ans - 1 << endl;
	return 0;
}