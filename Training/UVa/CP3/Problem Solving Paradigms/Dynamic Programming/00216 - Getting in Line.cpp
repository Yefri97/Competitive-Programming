// Traveling Salesman Problem (TSP)
#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)
#define mod(x,m) ((((x) % (m)) + (m)) % (m))
#define SQ(x) (x) * (x)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int INF = 1e9, MAXN = 10;

int n, X[MAXN], Y[MAXN];
double dist[MAXN][MAXN], memo[MAXN][1 << MAXN];

double solver(int pos, int bitmask) {
	if (bitmask == (1 << n) - 1) return 0;
	if (memo[pos][bitmask] != -1.0) return memo[pos][bitmask];
	double ans = INF;
	fori(nxt, 0, n)
		if ((nxt != pos) && !(bitmask & (1 << nxt)))
			ans = min(ans, solver(nxt, bitmask | (1 << nxt)) + dist[pos][nxt]);
	return memo[pos][bitmask] = ans;
}

void print_ans(int pos, int bitmask) {
	if (bitmask == (1 << n) - 1) return;
	fori(nxt, 0, n) {
		if ((nxt != pos) && !(bitmask & (1 << nxt))) {
			if (memo[pos][bitmask] == solver(nxt, bitmask | (1 << nxt)) + dist[pos][nxt]) {
				cout << "Cable requirement to connect (" << X[pos] << "," << Y[pos] << ") to (" << X[nxt] << "," << Y[nxt] << ") is " << fixed << setprecision(2) << dist[pos][nxt] << " feet." << endl;
				print_ans(nxt, bitmask | (1 << nxt));
				break;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int cs = 0;
	while (cin >> n && n) {
		fori(i, 0, n)
			cin >> X[i] >> Y[i];
		fori(i, 0, n)
			fori(j, 0, n)
				dist[i][j] = sqrt(SQ(X[i] - X[j]) + SQ(Y[i] - Y[j])) + 16;
		fori(i, 0, MAXN) fori(j, 0, 1 << MAXN) memo[i][j] = -1.0;
		double ans = INF;
		fori(i, 0, n)
			ans = min(ans, solver(i, 1 << i));
		cout << "**********************************************************" << endl;
		cout << "Network #" << ++cs << endl;
		fori(i, 0, n) {
			if (ans == solver(i, 1 << i)) {
				print_ans(i, 1 << i);
				break;
			}
		}
		cout << "Number of feet of cable required is " << fixed << setprecision(2) << ans << "." << endl;
	}
	return 0;
}