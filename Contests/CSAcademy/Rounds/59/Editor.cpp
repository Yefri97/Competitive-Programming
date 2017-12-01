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

const int oo = 1e9, MX = 1000010;

int nxt[MX], val[MX];

int f(int x) { return nxt[x]; }

ii cycleFinding(int xo) {
  int tortoise = f(xo), hare = f(f(xo));
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(f(hare)); }
  int mu = 0; hare = xo;
  while (tortoise != hare) { tortoise = f(tortoise); hare = f(hare); mu++; }
  int lambda = 1; hare = f(hare);
  while (tortoise != hare) { hare = f(hare); lambda++; }
  return ii(mu, lambda);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n; cin >> n;
	ll w, h; cin >> w >> h;

	vi v(n);
	fori(i, 0, n)
		cin >> v[i];

	ll accv = accumulate(v.begin(), v.end(), 0LL) + n;

	for (int l = 0, r = 0, acc = 0, cnt = w / accv; l < n; l++) {
		while (acc + v[r] + 1 <= w % accv + 1) {
			acc += v[r] + 1;
			cnt += r == 0;
			r = (r + 1) % n;
		}
		nxt[l] = r;
		val[l] = cnt;
		acc -= v[l] + 1;
		cnt -= l == 0;
	}

	ii c = cycleFinding(0);

	ll ans = 0;
	if (h < c.first) {
		int u = 0;
		fori(i, 0, h) {
			ans += val[i];
			u = nxt[u];
		}
	} else {
		int a = 0, u = 0;

		fori(i, 0, c.first) {
			ans += val[u];
			u = nxt[u];
		}

		fori(i, 0, c.second) {
			a += val[u];
			u = nxt[u];
		}

		h -= c.first;
		ans += (h / c.second) * a;
		
		fori(i, 0, h % c.second) {
			ans += val[u];
			u = nxt[u];
		}
	}

	cout << ans << endl;
	return 0;
}