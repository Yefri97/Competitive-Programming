#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int c[] = {100, 20, 10, 5, 1};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	int ans = 0;
	fori(i, 0, 5) {
		ans += (n / c[i]);
		n %= c[i];
	}
	cout << ans << endl;
	return 0;
}
