#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9, MN = 55;

int A[MN][MN];

int di[] = {0, -1, 0, 1, 0};
int dj[] = {0, 0, 1, 0, -1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	fori(i, 0, n)
		fori(j, 0, m)
			cin >> A[i][j];
	int ans = 0;
	fori(i1, 1, n - 1) {
		fori(j1, 1, m - 1) {
			fori(i2, 1, n - 1) {
				fori(j2, 1, m - 1) {
					if (abs(i2 - i1) + abs(j2 - j1) < 3) continue;
					int sum = 0;
					fori(k, 0, 5)
						sum += A[i1 + di[k]][j1 + dj[k]] * A[i2 + di[k]][j2 + dj[k]];
					ans = max(ans, sum);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
