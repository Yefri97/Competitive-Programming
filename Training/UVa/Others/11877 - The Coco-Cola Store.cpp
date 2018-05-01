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
	int bottles;
	while (cin >> bottles && bottles) {
		int ans = 0;
		while (bottles >= 3) {
			int tmp = bottles / 3;
			ans += tmp;
			tmp += bottles % 3;
			bottles = tmp;
		}
		if (bottles == 2) ans++;
		cout << ans << endl;
	}
	return 0;
}