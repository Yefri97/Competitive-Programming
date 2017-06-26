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

const int INF = 1e9, MAXN = 60;

int input[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, m)
		cin >> input[i];
	sort(input, input + m);
	int ans = 1000;
	for (int a = 0, b = n - 1; b < m; b++, a++)
		ans = min(ans, input[b] - input[a]);
	cout << ans << endl;
	return 0;
}