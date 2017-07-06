// Max 2D Range Sum
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

const int INF = 1e9, MAXN = 110;
int A[MAXN][MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, cs = 0; cin >> t;
	while (t--) {
		int n, m, k; cin >> n >> m >> k;
		fori(i, 0, n)
			fori(j, 0, m)
				cin >> A[i][j];
		fori(i, 0, n)
			fori(j, 1, m)
				A[i][j] += A[i][j - 1];
		int max_area = 0, cost = 0;
		fori(a, 0, m) {
			fori(b, 0, a + 1) {
				vi v;
				fori(i, 0, n)
					v.push_back(A[i][a] - (b == 0 ? 0 : A[i][b - 1]));
				int sum = 0;
				for (int r = 0, l = 0; r < n; r++) {
					sum += v[r];
					while (l <= r && sum > k) sum -= v[l], l++;
					int area = (r - l + 1) * (a - b + 1);
					if (area > max_area) {
						max_area = area;
						cost = sum;
					} else if (area == max_area) {
						cost = min(cost, sum);
					}
				}
			}
		}
		cout << "Case #" << ++cs << ": " << max_area << " " << cost << endl;
	}
	return 0;
}