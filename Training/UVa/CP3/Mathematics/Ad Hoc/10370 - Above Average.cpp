// Mathematical Simulation (Brute Force), Easier
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

const int INF = 1e9, MAXN = 1010;

int input[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fori(i, 0, n)
			cin >> input[i];
		double prom = (double)accumulate(input, input + n, 0) / (double)n;
		int cont = 0;
		fori(i, 0, n)
			cont += (input[i] > prom);
		cout << fixed << setprecision(3) << (cont * 100) / (double)n << "%" << endl;
	}
	return 0;
}