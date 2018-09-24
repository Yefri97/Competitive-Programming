#include <bits/stdc++.h>
#define endl '\n'
#define debug(X) cout << #X << " = " << X << endl
#define fori(i,b,e) for (int i = (b); i < (e); ++i)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int oo = 1e9;

int a[4][3][2];

int h(char c) { return (c == 'S' ? 0 : c == 'M' ? 1 : 2); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	fori(i, 0, n) {
		string s; cin >> s;
		a[s.size() - 1][h(s.back())][0]++;
	}
	fori(i, 0, n) {
		string s; cin >> s;
		a[s.size() - 1][h(s.back())][1]++;
	}
	int ans = 0;
	fori(i, 0, 4) {
		fori(j, 0, 3) {
			int k = min(a[i][j][0], a[i][j][1]);
			ans += a[i][j][1] - k;
		}
	}
	cout << ans << endl;
	return 0;
}
