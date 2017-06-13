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

const int INF = 1e9;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, m; cin >> n >> m;
	vector<vi> music(n, vi(m));
	fori(i, 0, n) {
		int k; cin >> k;
		fori(j, 0, k) {
			int song; cin >> song; song--;
			music[i][song] = 1;
		}
	}
	int ans = 0;
	fori(i, 0, n) {
		fori(j, i + 1, n) {
			int cont = 0;
			fori(k, 0, m) {
				cont += (music[i][k] && music[j][k]);
			}
			ans = max(ans, cont);
		}
	}
	cout << ans << endl;
	return 0;
}