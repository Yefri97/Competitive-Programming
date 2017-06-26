// Working with Prime Factors
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
	int n;
	while (cin >> n && n) {
		vector<int> v(n + 1), result(n + 1);
		for (int i = 1; i <= n; i++) v[i] = i;
		for (int i = 2; i <= n; i++) if (v[i] != 1) {
			for (int j = i; j <= n; j += i) {
				while (v[j] % i == 0) {
					v[j] /= i;
					result[i]++;
				}
			}
		}
		cout << setw(3) << n << "! =";
		for (int i = 1, k = 0; i <= n; i++) {
			if (result[i]) {
				if (k != 0 && k % 15 == 0)
					cout << endl << setw(9) << result[i];
				else
					cout << setw(3) << result[i];
				k++;
			}
		}
		cout << endl;
	}
	return 0;
}