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

const int INF = 1e9, MAXN = 50;
int width[MAXN];

char solver(int n, int k) {
	if (n == 0) return 'a';
	if (n == 1) return 'b';
	if (n == 2) return 'c';
	if (k <= width[n - 1]) return solver(n - 1, k);
	if (k <= width[n - 1] + width[n - 2]) return solver(n - 2, k - width[n - 1]);
	return solver(n - 3, k - width[n - 1] - width[n - 2]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k; cin >> n >> k;
	width[0] = width[1] = width[2] = 1;
	fori(i, 3, n + 1)
		width[i] = width[i - 1] + width[i - 2] + width[i - 3];
	if (width[n] < k) {
		cout << -1 << endl;
	} else {
		char c = solver(n, k);
		cout << c << endl;
	}
	return 0;
}