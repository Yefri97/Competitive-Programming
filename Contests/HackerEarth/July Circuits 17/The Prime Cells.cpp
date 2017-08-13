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

const int oo = 1e9;

bitset<410> bs;

int A[110][110];

int mi[] = {-1, 0, 1, 0};
int mj[] = {0, 1, 0, -1};

void sieve(int n) {
	bs.set();
	for (int i = 2; i * i <= n; i++) if (bs.test(i))
		for (int j = i * i; j <= n; j += i) bs.reset(j);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	sieve(400);
	int n; cin >> n;
	fori(i, 0, n)
		fori(j, 0, n)
			cin >> A[i][j];
	int ans = 0;
	fori(i, 0, n) {
		fori(j, 0, n) {
			int x = 0;
			fori(k, 0, 4) {
				int ni = i + mi[k], nj = j + mj[k];
				if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
				x += A[ni][nj];
			}
			ans += bs.test(x);
		}
	}
	cout << ans << endl;
	return 0;
}