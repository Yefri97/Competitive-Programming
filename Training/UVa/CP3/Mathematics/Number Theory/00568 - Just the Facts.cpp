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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	while (cin >> n) {
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			int x = i;
			while (x % 5 == 0) x /= 5, cnt++;
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			int x = i;
			while (cnt && x % 2 == 0) x /= 2, cnt--;
			while (x % 5 == 0) x /= 5;
			ans = (ans * x) % 10;
		}
		cout << setw(5) << n << " -> " << ans << endl;
	}
	return 0;
}