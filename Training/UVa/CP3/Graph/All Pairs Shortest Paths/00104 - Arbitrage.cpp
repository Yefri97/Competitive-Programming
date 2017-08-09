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

const int oo = 1e9, mxn = 30;

double g[mxn][mxn][mxn];
int p[mxn][mxn][mxn];

void printPath(int s, int t, int m) {
	if (m == -1) {
		cout << t + 1 << " ";
	} else {
		printPath(s, p[s][t][m], m - 1);
		cout << t + 1 << " ";
	}
}

void solver(int n) {
	fori(m, 1, n) {
		fori(k, 0, n) {
			fori(i, 0, n) {
				fori(j, 0, n) {
					double val = g[i][k][m - 1] * g[k][j][0];
					if (val > g[i][j][m]) {
						g[i][j][m] = val;
						p[i][j][m] = k;
					}
					if (i == j && val >= 1.01) {
						printPath(i, p[i][i][m], m - 1);
						cout << i + 1 << endl;
						return;
					}
				}
			}
		}
	}
	cout << "no arbitrage sequence exists" << endl;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		memset(g, 0, sizeof g);
		fori(i, 0, n) {
			fori(j, 0, n) {
				if (i == j)
					g[i][i][0] = 1.0;
				else
					cin >> g[i][j][0];
				p[i][j][0] = i;
			}
		}
		solver(n);
	}
	return 0;
}