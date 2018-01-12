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
typedef pair<ll, ii> iii;

const int oo = 1e9;

int n, m, r, k;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

ll f(ii pos) { 
	int x = pos.first, y = pos.second;
	return (1LL * (min(n + 1, x + r) - max(r, x))) * (1LL * (min(m + 1, y + r) - max(r, y)));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> r >> k;
	priority_queue< iii > pq;
	set<ii> used;
	ii init = ii((n + 1) / 2, (m + 1) / 2);
	pq.push(iii(f(init), init));
	used.insert(init);
	ll acc = 0;
	while (k--) {
		iii top = pq.top(); pq.pop();
		ll w = top.first;
		ii pos = top.second;
		acc += w;
		fori(i, 0, 4) {
			ii new_pos = ii(pos.first + dx[i], pos.second + dy[i]);
			if (used.find(new_pos) == used.end()) {
				pq.push(iii(f(new_pos), new_pos));
				used.insert(new_pos);
			}
		}
	}
	double ans = (double)acc / ((1LL * (n - r + 1)) * (1LL * (m - r + 1)));
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}