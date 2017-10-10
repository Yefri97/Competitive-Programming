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

const int oo = 1e9, mxn = 100010;

int C[mxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n, k;
	while (cin >> n >> k && n != -1) {
		fori(i, 0, n + 1)
			cin >> C[i];
		reverse(C, C + n + 1);
		fori(i, 0, n - k + 1) {
			C[k + i] -= C[i];
			C[i] = 0;
		}
		int d = 0;
		while (d <= n && C[d] == 0) d++;
		cout << C[n];
		for (int i = n - 1; i >= d; i--)
			cout << " " << C[i];
		cout << endl;
	}
	return 0;
}